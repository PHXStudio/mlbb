#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;

/// <summary>
/// Unity 5.6：批量清理 Assets/ResData/Role/Prefabs 下预制体上的 Missing Script 槽位。
/// 若仅在运行时从 .bytes 报错、编辑器打开 prefab 无 Missing，则需重新打 Player 包而非运行本菜单。
/// </summary>
public static class RolePrefabMissingScriptCleanup
{
    const string PrefabSearchFolder = "Assets/ResData/Role/Prefabs";

    [MenuItem("MLBB/Remove Missing Scripts on Role Prefabs")]
    static void RemoveMissingOnAllRolePrefabs()
    {
        string[] guids = AssetDatabase.FindAssets("t:Prefab", new[] { PrefabSearchFolder });
        int prefabsChanged = 0;
        int totalRemoved = 0;

        foreach (string guid in guids)
        {
            string path = AssetDatabase.GUIDToAssetPath(guid);
            GameObject prefabAsset = AssetDatabase.LoadAssetAtPath<GameObject>(path);
            if (prefabAsset == null)
                continue;

            GameObject instance = (GameObject)PrefabUtility.InstantiatePrefab(prefabAsset);
            if (instance == null)
                continue;

            try
            {
                int removed = RemoveMissingScriptsInHierarchy(instance);
                if (removed > 0)
                {
                    PrefabUtility.ReplacePrefab(instance, prefabAsset, ReplacePrefabOptions.ConnectToPrefab);
                    prefabsChanged++;
                    totalRemoved += removed;
                    Debug.Log("[MLBB] " + path + " — removed " + removed + " missing script slot(s).");
                }
            }
            finally
            {
                Object.DestroyImmediate(instance);
            }
        }

        AssetDatabase.SaveAssets();
        EditorUtility.DisplayDialog(
            "MLBB",
            "扫描完成：修改了 " + prefabsChanged + " 个 prefab，共去掉 " + totalRemoved + " 处 Missing Script 槽位。\n若运行时仍报 MissingScript，请重新导出对应 Player/*.bytes。",
            "OK");
    }

    static int RemoveMissingScriptsInHierarchy(GameObject root)
    {
        int n = 0;
        Transform[] trs = root.GetComponentsInChildren<Transform>(true);
        foreach (Transform t in trs)
            n += RemoveMissingScriptsOnGameObject(t.gameObject);
        return n;
    }

    /// <summary>Unity 5.6 无 GameObjectUtility.RemoveMonoBehavioursWithMissingScript 时的写法。</summary>
    static int RemoveMissingScriptsOnGameObject(GameObject go)
    {
        SerializedObject so = new SerializedObject(go);
        SerializedProperty prop = so.FindProperty("m_Component");
        if (prop == null || !prop.isArray)
            return 0;

        int removed = 0;
        for (int i = prop.arraySize - 1; i >= 0; i--)
        {
            SerializedProperty elem = prop.GetArrayElementAtIndex(i);
            SerializedProperty cref = elem.FindPropertyRelative("component");
            if (cref == null)
                continue;
            if (cref.objectReferenceValue != null)
                continue;
            prop.DeleteArrayElementAtIndex(i);
            if (i < prop.arraySize)
            {
                SerializedProperty elem2 = prop.GetArrayElementAtIndex(i);
                SerializedProperty cref2 = elem2 != null ? elem2.FindPropertyRelative("component") : null;
                if (cref2 != null && cref2.objectReferenceValue == null)
                    prop.DeleteArrayElementAtIndex(i);
            }
            removed++;
        }

        if (removed > 0)
            so.ApplyModifiedProperties();
        return removed;
    }
}
#endif
