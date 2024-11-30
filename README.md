# PortableLuaEnv
**PortableLuaEnv** is a lightweight, portable and self-contained scripting environment for Lua designed for fast and hassle-free use. It includes everything you need to run Lua scripts without requiring installation, system integration, or additional setup. Just add your scripts, and you're ready to go.

This project is ideal for those who want a portable and minimal Lua scripting solution with support for external libraries and extensions. Its simplicity makes it easier to set up and use compared to traditional environments like Python, while still offering extensibility through custom C++-written Lua libraries.

## Features

- **Self-contained environment**: All components needed to run Lua scripts are included.
- **No installation or integration**: Just extract the folder and start scripting.
- **Script-first approach**: Simply add your scripts to the `scripts/lua` folder.
- **Extensibility**: Add external Lua libraries or custom C++-compiled Lua DLLs in the `libs` folder.
- **Sample files included**:
  - A test script (`test.lua`) to ensure the environment is set up and functioning.
  - A demonstration library (`filesystem.lua`) showing how to add and use external libraries.


## Getting Started

1. **Download and extract PortableLuaEnv**: 
   Clone or download the repository and unzip it.
   
   ```bash
   git clone https://github.com/your-username/PortableLuaEnv.git
   cd PortableLuaEnv
   ```

2. **Add your scripts**: 
   Place your `.lua` scripts in the `scripts\lua` folder.

3. **Run the environment**: 
   Use the included executable to run Lua scripts.

   Example command:
   ```bash
   ./scripts/lua/tests/test_lua.bat
   ```

4. **Add external libraries (optional)**: 
   Place your custom libraries in the `libs` folder. These can be standard Lua files or C++-compiled DLLs.


## Directory Structure

```
PortableLuaEnv/
├── scripts/       
│   └── lua                
        ├── additional/     # Useful links
        ├── assets/         # The Lua logo to embed into Lua executables
        ├── binaries/       # Lua binaries and dynamic library
        ├── compiler/       # Rtc compiler for compiling Lua scripts into executables
        ├── libs/           # Library storage folder
        └── tests/          # Tests
├── README.md           # Project documentation
└── LICENSE             # License file
```

## Why PortableLuaEnv?

### **Ease of Use**
- Unlike Python environments, which often require dependency management tools and virtual environments, PortableLuaEnv provides a zero-hassle setup.

### **Portability**
- LuaScriptEnv works out-of-the-box without modifying your system configuration or requiring administrative privileges.

### **Extensibility**
- Support for dynamic linking with custom C++ Lua libraries allows for powerful customization and feature expansion.


## Contributing

Contributions are welcome! If you have ideas for new features or improvements, feel free to fork the repository and create a pull request.

## License

This project is licensed under the GNU GPL v3 License. See the `LICENSE` file for details.

---

Enjoy effortless Lua scripting with **PortableLuaEnv**!
