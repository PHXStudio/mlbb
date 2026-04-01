using UnityEngine;
using UnityEditor;
using System.IO;
using System.Collections.Generic;
using System.Collections;

using System.Threading;

public class BuildAsset : MonoBehaviour
{

#if UNITY_IOS || UNITY_IPHONE
    const BuildTarget target_ = BuildTarget.iPhone;
#elif UNITY_ANDROID
    const BuildTarget target_ = BuildTarget.Android;
#else
    const BuildTarget target_ = BuildTarget.StandaloneWindows;
#endif

    static string configFolder_ = Application.dataPath + "/../../config/Tables";

    const string resourceFolder_ = "Assets/ResData/";

    const string playerPrefabFolder_ = resourceFolder_ + "Role/Prefabs/";
    const string uiPrefabFolder_ = resourceFolder_ + "UI/UIPrefab/";
    const string weaponPrefabFolder_ = resourceFolder_ + "Weapon/";
    const string effectPrefabFolder_ = resourceFolder_ + "Effect/Prefab/";
    const string soundPrefabFolder_ = resourceFolder_ + "Sound/";

    const string musicPrefabFolder_ = resourceFolder_ + "Music/";
    const string iconPrefabFolder_ = resourceFolder_ + "Icon/";


    static string playerBundleOutputFolder_  = Configure.StreamAssetsFolder + "/Player/";
    static string uiBundleOutputFolder_ = Configure.StreamAssetsFolder + "/UI/";
    static string weaponBundleOutputFolder_ = Configure.StreamAssetsFolder + "/Weapon/";
    static string effectBundleOutputFolder_ = Configure.StreamAssetsFolder + "/Effect/";
    static string soundBundleOutputFolder_ = Configure.StreamAssetsFolder + "/Sound/";
    static string musicBundleOutputFolder_ = Configure.StreamAssetsFolder + "/Music/";
    static string iconBundleOutputFolder_ = Configure.StreamAssetsFolder + "/Icon/";
  
    static string playerDependConfigFileName_ = Configure.TableFolder + "PlayerDependence.json";
    static string uiDependConfigFileName_ = Configure.TableFolder + "UIDependence.json";
    static string effectDependConfigFileName_ = Configure.TableFolder + "EffectDependence.json";

    static Dictionary<string, List<string>> playerRefDic_ = new Dictionary<string, List<string>>();
    static Dictionary<string, List<string>> uiRefDic_ = new Dictionary<string, List<string>>();
    static Dictionary<string, List<string>> effectRefDic_ = new Dictionary<string, List<string>>();

    static string crtUI_;
    static string crtPlayer_;
    static string crtEffect_;
    static string[] ExcludeUI = new string[] { "" };

    static void initPlayerRefAssets()
    {
        string jsonStr = File.ReadAllText(playerDependConfigFileName_);
        playerRefDic_ = LitJson.JsonMapper.ToObject<Dictionary<string, List<string>>>(jsonStr);
    }

    static List<string> getPlayerRefAssets(string playerName)
    {
        if (!playerRefDic_.ContainsKey(playerName))
            return null;
        return playerRefDic_[playerName];   
    }

    static void initUIRefAtlas()
    {
        string jsonStr = File.ReadAllText(uiDependConfigFileName_);
        uiRefDic_ = LitJson.JsonMapper.ToObject<Dictionary<string, List<string>>>(jsonStr);
    }
    static List<string> getUIRefAtlas(string uiName)
    {
        if (!uiRefDic_.ContainsKey(uiName))
            return new List<string>();
        return uiRefDic_[uiName];
    }
    static string findUIAtlas(string fileName)
    {
        string[] fileGuids = AssetDatabase.FindAssets(fileName + " t:GameObject", new string[] { "Assets/ResData/UI/UIAtlass" });
        if (fileGuids == null || fileGuids.Length == 0)
        {
            UnityEngine.Debug.LogError("Can not found atlas by " + fileName + " in project: ");
            return "";
        }
        string finalPath = "";
        if (fileGuids.Length > 1)
        {
            UnityEngine.Debug.LogError("More atlas by " + fileName + " in project: ");
            for (int i = 0; i < fileGuids.Length; ++i)
            {
                UnityEngine.Debug.LogError(AssetDatabase.GUIDToAssetPath(fileGuids[i]));
                if (!AssetDatabase.GUIDToAssetPath(fileGuids[i]).Contains(fileName + ".prefab"))
                    continue;
                finalPath = AssetDatabase.GUIDToAssetPath(fileGuids[i]);
                UnityEngine.Debug.LogError("Use this Above.");
            }
        }
        else
        {
            finalPath = AssetDatabase.GUIDToAssetPath(fileGuids[0]);
        }

        return finalPath;
    }

    static void initEffectRefAssets()
    {
        string jsonStr = File.ReadAllText(effectDependConfigFileName_);
        effectRefDic_ = LitJson.JsonMapper.ToObject<Dictionary<string, List<string>>>(jsonStr);
    }

    static List<string> getRefEffAssets(string effectName)
    {
        if (!effectRefDic_.ContainsKey(effectName))
            return null;
        return effectRefDic_[effectName];
    }

    static string assetGuid2Path(string assetGuid)
    {
        return AssetDatabase.GUIDToAssetPath(assetGuid);
    }

    static void mkdir(string dir)
    {
        if (Directory.Exists(dir))
            Directory.Delete(dir, true);
        Directory.CreateDirectory(dir);
    }
    static List<UnityEngine.Object> filter(string dir)
    {
        List<Object> res = new List<Object>();

        string[] files = Directory.GetFiles(dir, "*", SearchOption.AllDirectories);
        for (int i = 0; i < files.Length; ++i)
        {
            if (files[i].Contains(".meta"))
                continue;
            string name = files[i].Substring(files[i].IndexOf("Assets"));
            Object file = AssetDatabase.LoadAssetAtPath(name, typeof(Object));
            if (file != null)
                res.Add(file);
        }

        return res;
    }
    static void directoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
    {
        DirectoryInfo dir = new DirectoryInfo(sourceDirName);
        DirectoryInfo[] dirs = dir.GetDirectories();
        if (!dir.Exists)
        {
            throw new DirectoryNotFoundException(
                "Source directory does not exist or could not be found: "
                + sourceDirName);
        }
        if (!Directory.Exists(destDirName))
        {
            Directory.CreateDirectory(destDirName);
        }
        FileInfo[] files = dir.GetFiles();
        foreach (FileInfo file in files)
        {
            string temppath = Path.Combine(destDirName, file.Name);
            file.CopyTo(temppath, false);
        }
        if (copySubDirs)
        {
            foreach (DirectoryInfo subdir in dirs)
            {
                string temppath = Path.Combine(destDirName, subdir.Name);
                directoryCopy(subdir.FullName, temppath, copySubDirs);
            }
        }
    }

    [MenuItem("BuildToolset/CopyConfig")]
    public static void BuildConfig()
    {
        directoryCopy(configFolder_, Configure.TableFolder, true);


    }

    [MenuItem("BuildToolset/MakePlayers")]
    public static void BuildPlayers()
    {

        mkdir(playerBundleOutputFolder_);
        Caching.ClearCache();
        //dep角色shader
        { 
            BuildPipeline.PushAssetDependencies();
            string[] assetfiles = new string[] { "Assets/Scripts/Shader/PlayerShader.shader", "Assets/ResData/Role/yingzi/yingzi01.mat" };
            Object[] objfiles = new Object[assetfiles.Length];
            for (int i = 0; i < objfiles.Length; ++i)
            {
                objfiles[i] = AssetDatabase.LoadMainAssetAtPath(assetfiles[i]);
                BuildPipeline.BuildAssetBundle(null, objfiles, string.Format(playerBundleOutputFolder_ + "{0}.bytes", "PlayerShader"), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
            }
        }

        {

            initPlayerRefAssets();
            List<Object> files = filter(playerPrefabFolder_);
            BuildPipeline.PushAssetDependencies();
            for (int i = 0; i < files.Count; ++i)
            {
                List<string> pr = getPlayerRefAssets(files[i].name);
                if (pr != null)
                {
                    BuildPipeline.PushAssetDependencies();

                    //List<Object> refAsssets = new List<Object>();
                    for (int j = 0; j < pr.Count; ++j)
                    {
                        string assetfile = assetGuid2Path(pr[j]);
                        Object mainAsset = AssetDatabase.LoadMainAssetAtPath(assetfile);
                        BuildPipeline.BuildAssetBundle(mainAsset, null, string.Format(playerBundleOutputFolder_ + "{0}.bytes", pr[j]), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
                        //refAsssets.Add(mainAsset);
                    }
                }
                //if (refAsssets.Count > 0)
                //    BuildPipeline.BuildAssetBundle(null, refAsssets.ToArray(), string.Format(pathName + "{0}{1}.bytes", files[i].name, "_dep"), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, tar);

                BuildPipeline.BuildAssetBundle(files[i], null, string.Format(playerBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
            }
            BuildPipeline.PopAssetDependencies();
            //if (refAsssets.Count > 0)
            BuildPipeline.PopAssetDependencies();
        }
        AssetDatabase.Refresh();
        
    }
    [MenuItem("BuildToolset/MakeUI")]
    static void BuildUI()
    {
        mkdir(uiBundleOutputFolder_);
        Caching.ClearCache();
        { 
            //dep字体(所有ui)
            BuildPipeline.PushAssetDependencies();
            string[] assetfiles = new string[] { "Assets/ResData/Font/qingyuan.ttf",
                                                    "Assets/ResData/Font/minijianshaoer.ttf",
                                                    "Assets/Scripts/NGUI/Scripts/UI/UIAtlas.cs",
                                                    "Assets/Scripts/NGUI/Scripts/UI/UIFont.cs",
                                                    "Assets/Scripts/NGUI/Resources/Shaders/Unlit - Transparent Colored.shader"};
            Object[] objfiles = new Object[assetfiles.Length];
            for (int i = 0; i < objfiles.Length; ++i)
            {
                objfiles[i] = AssetDatabase.LoadMainAssetAtPath(assetfiles[i]);
            }
            BuildPipeline.BuildAssetBundle(null, objfiles, string.Format(uiBundleOutputFolder_ + "{0}.bytes", "commonAssets"), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
        }

        {
            initUIRefAtlas();
            List<Object> files = filter(uiPrefabFolder_);
            for (int i = 0; i < files.Count; ++i)
            {
                
                    List<string> refatlasLst = getUIRefAtlas(files[i].name);
                    if (refatlasLst.Count > 0)
                        BuildPipeline.PushAssetDependencies();
                    for (int j = 0; j < refatlasLst.Count; ++j)
                    {
                        string assetfile = findUIAtlas(refatlasLst[j]);
                        Object mainAsset = AssetDatabase.LoadMainAssetAtPath(assetfile);
                        BuildPipeline.BuildAssetBundle(mainAsset, null, string.Format(uiBundleOutputFolder_ + "{0}.bytes", refatlasLst[j]), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
                    }
                    BuildPipeline.PushAssetDependencies();
                    BuildPipeline.BuildAssetBundle(files[i], null, string.Format(uiBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
                    BuildPipeline.PopAssetDependencies();
                    if (refatlasLst.Count > 0)
                        BuildPipeline.PopAssetDependencies();
            }

        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/MakeEffect")]
    public static void BuildEffect()
    {
        mkdir(effectBundleOutputFolder_);
        Caching.ClearCache();
        {
            initEffectRefAssets();
            List<Object> files = filter(effectPrefabFolder_);
            for (int i = 0; i < files.Count; ++i)
            {
                List<string> pr = getRefEffAssets(files[i].name);
                if (pr != null)
                {
                    BuildPipeline.PushAssetDependencies();

                    //List<Object> refAsssets = new List<Object>();
                    for (int j = 0; j < pr.Count; ++j)
                    {
                        string assetfile = assetGuid2Path(pr[j]);
                        Object mainAsset = AssetDatabase.LoadMainAssetAtPath(assetfile);
                        if (mainAsset == null)
                        {
                            UnityEngine.Debug.Log(assetfile + " is can not find.");
                            continue;
                        }
                        BuildPipeline.BuildAssetBundle(mainAsset, null, string.Format(effectBundleOutputFolder_ + "{0}.bytes", pr[j]), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
                        //refAsssets.Add(mainAsset);
                    }
                }
                else
                {
                    UnityEngine.Debug.Log(files[i].name + " is can not find file effect.");
                }
                //if (refAsssets.Count > 0)
                //    BuildPipeline.BuildAssetBundle(null, refAsssets.ToArray(), string.Format(pathName + "{0}{1}.bytes", files[i].name, "_dep"), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, tar);
                BuildPipeline.PushAssetDependencies();
                BuildPipeline.BuildAssetBundle(files[i], null, string.Format(effectBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
                BuildPipeline.PopAssetDependencies();
                //if (refAsssets.Count > 0)
                BuildPipeline.PopAssetDependencies();
            }
        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/Weapon")]
    public static void BuildWeapon()
    {
        mkdir(weaponBundleOutputFolder_);
        Caching.ClearCache();
        List<Object> files = filter(weaponPrefabFolder_);
        for (int i = 0; i < files.Count; ++i)
        {
            BuildPipeline.BuildAssetBundle(files[i], null, string.Format(weaponBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/MakeSound")]
    public static void BuildSound()
    {
        mkdir(soundBundleOutputFolder_);
       // Caching.CleanCache();
        List<Object> files = filter(soundPrefabFolder_);
        for (int i = 0; i < files.Count; ++i)
        {
            BuildPipeline.BuildAssetBundle(files[i], null, string.Format(soundBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/MakeMusic")]
    public static void BuildMusic()
    {
        mkdir(musicBundleOutputFolder_);
        Caching.ClearCache();
        List<Object> files = filter(musicPrefabFolder_);
        for (int i = 0; i < files.Count; ++i)
        {
            BuildPipeline.BuildAssetBundle(files[i], null, string.Format(musicBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/MakeIcon")]
    public static void BuildIcon()
    {
        mkdir(iconBundleOutputFolder_);
        Caching.ClearCache();
        List<Object> files = filter(iconPrefabFolder_);
        for (int i = 0; i < files.Count; ++i)
        {
            BuildPipeline.BuildAssetBundle(files[i], null, string.Format(iconBundleOutputFolder_ + "{0}.bytes", files[i].name), BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.DeterministicAssetBundle, target_);
        }
        AssetDatabase.Refresh();
    }
    [MenuItem("BuildToolset/CreateUIDependence")]
    public static void CreateUIDependence()
    {
        uiRefDic_.Clear();
        string path = uiPrefabFolder_;
        string[] filePaths = Directory.GetFiles(path, "*", SearchOption.AllDirectories);
        for (int i = 0; i < filePaths.Length; ++i)
        {
            if (filePaths[i].Contains(".meta"))
                continue;
            string filePath = filePaths[i].Substring(filePaths[i].IndexOf("Assets"));
            if (Contain(filePath))
                continue;
            Object file = AssetDatabase.LoadAssetAtPath(filePath, typeof(Object));
            crtUI_ = file.name;
            ListAtlas(((GameObject)file).transform);
        }
        string jsonStr = LitJson.JsonMapper.ToJson(uiRefDic_);
        File.WriteAllText(configFolder_ + "/UIDependence.json", jsonStr);
        AssetDatabase.Refresh();
        UnityEngine.Debug.Log("CreateUIDependence Success");
    }

    static bool Contain(string fileName)
    {
        for (int i = 0; i < ExcludeUI.Length; ++i)
        {
            if (ExcludeUI[i].Equals(fileName))
                return true;
        }
        return false;
    }

    static void ListAtlas(Transform trans)
    {
        UISprite sprite = trans.GetComponent<UISprite>();
        if (sprite != null && sprite.atlas != null)
        {
            if (!uiRefDic_.ContainsKey(crtUI_))
                uiRefDic_.Add(crtUI_, new List<string>());
            if (!uiRefDic_[crtUI_].Contains(sprite.atlas.name))
                uiRefDic_[crtUI_].Add(sprite.atlas.name);
        }
        for (int i = 0; i < trans.childCount; ++i)
        {
            ListAtlas(trans.GetChild(i));
        }
    }

    [MenuItem("BuildToolset/CreatePlayerDependence")]
    public static void CreatePlayerDependence()
    {
        playerRefDic_.Clear();
        string path = playerPrefabFolder_;
        string[] filePaths = Directory.GetFiles(path, "*", SearchOption.AllDirectories);
        for (int i = 0; i < filePaths.Length; ++i)
        {
            if (filePaths[i].Contains(".meta"))
                continue;
            string filePath = filePaths[i].Substring(filePaths[i].IndexOf("Assets"));
            Object file = AssetDatabase.LoadAssetAtPath(filePath, typeof(Object));
            crtPlayer_ = file.name;
            ListPlayerRef(((GameObject)file).transform);
        }
        string jsonStr = LitJson.JsonMapper.ToJson(playerRefDic_);
        File.WriteAllText(configFolder_ + "/PlayerDependence.json", jsonStr);
        AssetDatabase.Refresh();
        UnityEngine.Debug.Log("CreatePlayerDependence Success");
    }

    static void ListPlayerRef(Transform trans)
    {
        if (!playerRefDic_.ContainsKey(crtPlayer_))
        {
            playerRefDic_.Add(crtPlayer_, new List<string>());
        }

        Animator anim = trans.GetComponent<Animator>();
        string path = "";
        string guid = "";
        if (anim != null && anim.runtimeAnimatorController != null)
        {
            path = AssetDatabase.GetAssetPath(anim.runtimeAnimatorController);
            guid = AssetDatabase.AssetPathToGUID(path);
            if (!playerRefDic_[crtPlayer_].Contains(guid))
                playerRefDic_[crtPlayer_].Add(guid);
        }

        SkinnedMeshRenderer smr = trans.GetComponent<SkinnedMeshRenderer>();
        if (smr != null)
        {
            path = AssetDatabase.GetAssetPath(smr.sharedMaterial);
            guid = AssetDatabase.AssetPathToGUID(path);
            if (!playerRefDic_[crtPlayer_].Contains(guid))
                playerRefDic_[crtPlayer_].Add(guid);

            path = AssetDatabase.GetAssetPath(smr.sharedMaterial.mainTexture);
            guid = AssetDatabase.AssetPathToGUID(path);
            if (!playerRefDic_[crtPlayer_].Contains(guid))
                playerRefDic_[crtPlayer_].Add(guid);

            path = AssetDatabase.GetAssetPath(smr.sharedMesh);
            guid = AssetDatabase.AssetPathToGUID(path);
            if (!playerRefDic_[crtPlayer_].Contains(guid))
                playerRefDic_[crtPlayer_].Add(guid);
        }
        for (int i = 0; i < trans.childCount; ++i)
        {
            ListPlayerRef(trans.GetChild(i));
        }
    }

    [MenuItem("BuildToolset/CreateEffectDependence")]
    public static void CreateEffectDependence()
    {
        effectRefDic_.Clear();
        string path = effectPrefabFolder_;
        string[] filePaths = Directory.GetFiles(path, "*", SearchOption.AllDirectories);
        for (int i = 0; i < filePaths.Length; ++i)
        {
            if (filePaths[i].Contains(".meta"))
                continue;
            string filePath = filePaths[i].Substring(filePaths[i].IndexOf("Assets"));
            Object file = AssetDatabase.LoadAssetAtPath(filePath, typeof(Object));
            crtEffect_ = file.name;
            ListEffectRef(((GameObject)file).transform);
        }
        string jsonStr = LitJson.JsonMapper.ToJson(effectRefDic_);
        File.WriteAllText(configFolder_ + "/EffectDependence.json", jsonStr);
        AssetDatabase.Refresh();
        UnityEngine.Debug.Log("CreateEffectDependence Success");
    }

    static void AddEffectRef(Object obj)
    {
        if (obj == null) return;
        string path = AssetDatabase.GetAssetPath(obj);
        if (string.IsNullOrEmpty(path) || path.Equals("Resources/unity_builtin_extra")) return;
        string guid = AssetDatabase.AssetPathToGUID(path);
        if (!string.IsNullOrEmpty(guid) && !effectRefDic_[crtEffect_].Contains(guid))
            effectRefDic_[crtEffect_].Add(guid);
    }

    static void AddEffectRefFromMaterial(Material mat)
    {
        if (mat == null) return;
        AddEffectRef(mat);
        AddEffectRef(mat.mainTexture);
    }

    static void ListEffectRef(Transform trans)
    {
        if (!effectRefDic_.ContainsKey(crtEffect_))
        {
            effectRefDic_.Add(crtEffect_, new List<string>());
        }

        // Animation (legacy)
        Animation anima = trans.GetComponent<Animation>();
        if (anima != null)
        {
            foreach (AnimationState state in anima)
                AddEffectRef(state.clip);
        }

        // Animator
        Animator anim = trans.GetComponent<Animator>();
        if (anim != null)
            AddEffectRef(anim.runtimeAnimatorController);

        // MeshRenderer
        MeshRenderer mr = trans.GetComponent<MeshRenderer>();
        if (mr != null)
        {
            AddEffectRefFromMaterial(mr.sharedMaterial);
            MeshFilter mf = trans.GetComponent<MeshFilter>();
            if (mf != null)
                AddEffectRef(mf.sharedMesh);
        }

        // SkinnedMeshRenderer
        SkinnedMeshRenderer smr = trans.GetComponent<SkinnedMeshRenderer>();
        if (smr != null)
        {
            AddEffectRefFromMaterial(smr.sharedMaterial);
            AddEffectRef(smr.sharedMesh);
        }

        // ParticleSystem
        ParticleSystem ps = trans.GetComponent<ParticleSystem>();
        if (ps != null)
        {
            Renderer psr = ps.GetComponent<Renderer>();
            if (psr != null)
                AddEffectRefFromMaterial(psr.sharedMaterial);
        }

        // TrailRenderer
        TrailRenderer tr = trans.GetComponent<TrailRenderer>();
        if (tr != null)
            AddEffectRefFromMaterial(tr.sharedMaterial);

        // LineRenderer
        LineRenderer lr = trans.GetComponent<LineRenderer>();
        if (lr != null)
            AddEffectRefFromMaterial(lr.sharedMaterial);

        // Projector
        //Projector proj = trans.GetComponent<Projector>();
        //if (proj != null)
        //    AddEffectRefFromMaterial(proj.sharedMaterial);

        // Light (cookie texture)
        Light light = trans.GetComponent<Light>();
        if (light != null)
            AddEffectRef(light.cookie);

        // AudioSource
        AudioSource audio = trans.GetComponent<AudioSource>();
        if (audio != null)
            AddEffectRef(audio.clip);

        for (int i = 0; i < trans.childCount; ++i)
        {
            ListEffectRef(trans.GetChild(i));
        }
    }

    [MenuItem("BuildToolset/MakeAll")]
    public static void BuildAll()
    {
        AssetDatabase.Refresh();

        Thread thr = new Thread(BuildSound);

        /*StartCoroutine(buildEffect());
        StartCoroutine(buildUI());
        StartCoroutine(buildPlayers());
        StartCoroutine(buildWeapon());
        StartCoroutine(buildSound());
        StartCoroutine(buildMusic());
        StartCoroutine(buildIcon());*/

        thr.Start();

       
        
    }

  
    void buildEffect()
    {
        BuildEffect();
      
    }

    void buildUI()
    {
        BuildUI();
        
    }

    void buildPlayers()
    {
        BuildPlayers();
        
    }

    void buildWeapon()
    {
        BuildWeapon();
        
    }

    void buildSound()
    {
        BuildSound();
       
    }
    void buildMusic()
    {
        BuildMusic();
       
    }

    void buildIcon()
    {
        BuildIcon();
      
    }
}
