from environment import *
from libraries.ADLib.buildutil.ResourceOnlyProject import *

working_directory = os.path.dirname(os.path.realpath(__file__))
project = ResourceOnlyProject(env)
project.resource_output = os.path.join(working_directory, 'proj.ios.uk2/Resources')
project.resource_task = createResourceCompilerTask(
    os.path.join(working_directory, 'Resources_storage'),
    'kids-medium',
    'ios',
    ['en']
)

project.buildProject()
