# TkyoSpaghetti

This is an endless runner style game for the tkyosam fam. 

![Game screenshot](game_screenshot.png)

How to clone:

```
git clone --recurse-submodules https://github.com/Reesy/TkyoSpaghetti
```

This project imports it's dependency on SDL via a git submodule in the external_resources folder.

How to build:

Cmake is required to build this project, aswell as ensuring a suitable C++ compiler

To build a release (on OSX):

```
cmake .
make
```

To build with debug symbols (on OSX):
```
cmake -DCMAKE_BUILD_TYPE=Debug .
make
```

This project comes with a .vscode folder prebundled to make debugging easier, for this to work two plugins are necessary 

<dl>
    <dt> Recommended Plugins<dt>
    <dd style='color:green'>C/C++ Plugin </dd>
    <dd style='color:green'>CodeLLDB* </dd>
<dl>

\*CodeLLDB is only recommended for debugging on modern OSX versions

SDL2 can be found https://www.libsdl.org/

Art By: Brandon

Background Found here: https://wallpaperaccess.com/pixel-city

Music By: https://soundcloud.com/victor-bui-trong 
Collision sound: https://freesound.org/people/JustInvoke/sounds/446125/ 
Jump sound: https://freesound.org/people/elektroproleter/sounds/157568/
