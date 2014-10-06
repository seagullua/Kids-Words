TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += ../../../cocos2dx \
    ../../../cocos2dx/include \
    ../../../cocos2dx/kazmath/include \
    ../../../cocos2dx/platform/win32 \
    ../../../cocos2dx/platform/third_party/win32/ \
    ../../../cocos2dx/platform/third_party/win32/OGLES \
    ../Classes \
    ../../../CocosDenshion/include

include(../libraries/ADLib/ADLib.pri)

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin/debug/
} else {
    DESTDIR = $$PWD/bin/release/
}

#DEFINES +=NDEBUG
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/../../../Debug.win32/ -lglew32
    LIBS += -L$$PWD/../../../Debug.win32/ -llibcocos2d
    LIBS += -L$$PWD/../../../Debug.win32/ -llibCocosDenshion
    LIBS += -L$$PWD/../../../Debug.win32/ -llibcurl_imp
    LIBS += -lopengl32
} else {
    #LIBS += -L../../../Release.win32/ -llibcocos2d
    #LIBS += -L../../../Release.win32/ -lglew32
    #LIBS += -L../../../Release.win32/ -llibCocosDenshion
    #LIBS += -lopengl32
    DEFINES +=NDEBUG
}
LIBS += -luser32
QMAKE_CXXFLAGS_DEBUG += -wd4267 -wd4251 -wd4244
QMAKE_CXXFLAGS_RELEASE += -wd4267 -wd4251 -wd4244

DEFINES += WIN32 \
            _DEBUG \
            _WINDOWS \
            COCOS2D_DEBUG="1" \
            _CRT_SECURE_NO_WARNINGS \
            _SCL_SECURE_NO_WARNINGS

SOURCES += main.cpp \
    ../Classes/AppDelegate.cpp \
    PurchaseEmulator.cpp \
    ../Classes/Scenes/MainMenu.cpp \
    ../Classes/Scenes/SceneStyle.cpp \
    ../Classes/Scenes/Loading.cpp \
    ../Classes/Scenes/Settings.cpp \
    ../Classes/InfoStyles.cpp \
    ../Classes/Scenes/developers.cpp \
    ../Classes/Draw/Card.cpp \
    ../Classes/Draw/Stars.cpp \
    ../Classes/Scenes/SelectCollection.cpp \
    ../Classes/Logic/Collection.cpp \
    ../Classes/Logic/Word.cpp \
    ../Classes/Logic/Level.cpp \
    ../Classes/Logic/CollectionPart.cpp \
    ../Classes/Logic/LevelSaves.cpp \
    ../Classes/Scenes/SelectLevel.cpp \
    ../Classes/Scenes/LevelScene.cpp \
    ../Classes/Logic/Alphabete.cpp \
    ../Classes/Logic/StatusLetter.cpp \
    ../Classes/Logic/Letter.cpp \
    ../Classes/Logic/Task.cpp \
    ../Classes/Draw/TopPanell.cpp \
    ../Classes/Logic/OneSeason.cpp \
    ../Classes/Logic/OneGame.cpp \
    ../Classes/Draw/GameNode.cpp \
    ../Classes/Draw/LetterNode.cpp \
    ../Classes/Logic/Hint.cpp \
    ../Classes/PopUp/LevelEnd.cpp \
    ../Classes/PopUp/ExitGamePopUp.cpp \
    ../Classes/Managers/SettingsManager.cpp \
    ../Classes/PopUp/TurnOffPopUp.cpp \
    ../Classes/Managers/TutorialManager.cpp \
    ../Classes/Managers/SaveStarsManager.cpp \
    ../Classes/Managers/AdsManager.cpp

HEADERS += \
    ../Classes/AppMacros.h \
    ../Classes/AppDelegate.h \
    main.h \
    ../Classes/Scenes/MainMenu.h \
    ../Classes/Scenes/SceneStyle.h \
    ../Classes/Scenes/Loading.h \
    ../Classes/Scenes/Settings.h \
    ../Classes/InfoStyles.h \
    ../Classes/Scenes/developers.h \
    ../Classes/Draw/Card.h \
    ../Classes/Draw/Stars.h \
    ../Classes/Scenes/SelectCollection.h \
    ../Classes/Logic/Collection.h \
    ../Classes/Logic/Word.h \
    ../Classes/Logic/Level.h \
    ../Classes/Logic/CollectionPart.h \
    ../Classes/Logic/LevelSaves.h \
    ../Classes/Scenes/SelectLevel.h \
    ../Classes/Scenes/LevelScene.h \
    ../Classes/Logic/Alphabete.h \
    ../Classes/Logic/StatusLetter.h \
    ../Classes/Logic/Letter.h \
    ../Classes/Logic/Task.h \
    ../Classes/Draw/TopPanell.h \
    ../Classes/Logic/OneSeason.h \
    ../Classes/Logic/OneGame.h \
    ../Classes/Draw/GameNode.h \
    ../Classes/Draw/LetterNode.h \
    ../Classes/Logic/Hint.h \
    ../Classes/PopUp/LevelEnd.h \
    ../Classes/PopUp/ExitGamePopUp.h \
    ../Classes/Managers/SettingsManager.h \
    ../Classes/PopUp/TurnOffPopUp.h \
    ../Classes/Managers/TutorialManager.h \
    ../Classes/Managers/SaveStarsManager.h \
    ../Classes/Managers/AdsManager.h


