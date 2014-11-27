from libraries.ADLib.modules_android import *

from libraries.ADLib.buildutil.AndroidProject import *
from libraries.ADLib.buildutil.Modules import  *

modules = Modules()
loadModules(modules)

working_directory = os.path.dirname(os.path.realpath(__file__))

from environment import *

project = AndroidProject(env)
project.modules = modules

#Modules

project.addModule('android_ADStatistics_Flurry')
project.addModule('android_ADLanguage')
project.addModule('android_ADNotification')
project.addModule('android_ADBrowser')
project.addModule('android_ADFacebook_None')
project.addModule('android_ADHttp_None')


project.project_name = 'KidsWords2'
project.package_name = 'com.x4enjoy.kidswords2.ukrainian'
project.version_name = "1.00"
project.version_code = "2"
project.resources_compile_task = createResourceCompilerTask(
    os.path.join(working_directory, 'Resources_storage'),
    'kids-medium',
    'android',
    ['en']
)

project.signature = createAndroidSignature('Resources_storage/android/build.android/key.jks',
											'mavka',
                                           '', '')
project.res_dir = 'Resources_storage/android/build.android/res.uk'
project.working_directory = working_directory
project.addLookUpDir('libraries/ADLib/platform/Android/cpp')
project.addLookUpDir('libraries/ADLib/platform/Android/libs')
project.addLookUpDir('libraries/ADLib/platform/Android/java')
project.addLookUpDir('libraries/ADLib/platform/Android/res')
project.addLookUpDir('libraries/ADLib/src')
project.addLookUpDir('Classes')
project.main_activity_definition = project.getMainActivityDeclaration(screenOrientation="sensorLandscape")

project.addCppDir('libraries/ADLib/src')
project.addCppDir('Classes')
project.addCppDir('Versions/Language/Ukrainian')
project.addCppDir('Versions/Edition/AdsPurchase')
project.addCppDir('Versions/Level/KidsMedium')
