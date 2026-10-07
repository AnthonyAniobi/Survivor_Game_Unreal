# Survivor Game

Survivor Game is a third-person survival RPG prototype built with Unreal Engine. The project is designed as a foundation for exploration, character progression, combat, AI, and survival gameplay.

> **Project status:** Early development. The repository currently contains a playable third-person prototype and the initial C++/Blueprint structure for expanding it into a survival RPG.

## Requirements

- Unreal Engine **5.7**
- macOS (the project currently targets the Mac platform)
- Xcode and the macOS command-line developer tools for C++ builds
- Git

## Getting started

1. Clone the repository:

   ```bash
   git clone git@github.com:AnthonyAniobi/Survivor_Game_Unreal.git
   cd Survivor_Game_Unreal
   ```

2. Open [`SurvivalGame1.uproject`](./SurvivalGame1.uproject) with Unreal Engine 5.7.
3. Allow Unreal Engine to build or regenerate the project files when prompted.
4. Open the editor and press **Play** to launch the current third-person prototype.

The default editor and game map is `Content/ThirdPerson/Lvl_ThirdPerson.umap`.

## Current project features

- Third-person character movement and camera controls
- Jumping and mouse/gamepad look controls through Unreal's Enhanced Input system
- Blueprint-based third-person character, player controller, and game mode
- C++ gameplay module in `Source/SurvivalGame1`
- Reusable character module in `Source/TFCharacters`
- StateTree and GameplayStateTree plugins enabled for future gameplay and AI state logic
- Prototype level geometry and materials from the Level Prototyping collection
- Mac packaging/build configuration

## Controls

The current input assets are in `Content/Input`.

| Action | Default input |
| --- | --- |
| Move | Keyboard/gamepad movement axis |
| Look | Mouse or right stick |
| Jump | Jump action |

Input bindings can be edited in the Enhanced Input assets under `Content/Input/Actions` and `Content/Input/IMC_Default.uasset`.

## Project structure

```text
.
├── Config/                         Unreal project configuration
├── Content/
│   ├── Input/                      Enhanced Input actions and mappings
│   ├── LevelPrototyping/           Prototype meshes, materials, and textures
│   └── ThirdPerson/                Current map and Blueprint gameplay assets
├── Source/
│   ├── SurvivalGame1/              Main game module
│   └── TFCharacters/               Reusable character module
├── Build/Mac/                      Mac packaging resources
└── SurvivalGame1.uproject          Unreal project descriptor
```

## C++ modules

### `SurvivalGame1`

The main runtime module. It contains the project character, game mode, player controller, and module startup code. Its dependencies include Enhanced Input, AI Module, StateTree, GameplayStateTree, UMG, and Slate.

### `TFCharacters`

A reusable character module containing the base character and player-character classes. It provides a place to centralize character movement, camera, input, and perspective behavior as the project grows.

## Development workflow

- Make gameplay and world changes in the Unreal Editor.
- Keep reusable gameplay logic in the appropriate C++ module and expose tunable values to Blueprints where useful.
- Use the existing Enhanced Input assets for new player actions.
- Use StateTree or GameplayStateTree for state-driven character and AI behavior.
- Do not commit generated Unreal folders such as `Binaries`, `DerivedDataCache`, `Intermediate`, or `Saved` unless a specific build or debugging artifact is intentionally required.

## Building and packaging

For local development, open the project in Unreal Editor and let Unreal compile the C++ modules. To create a Mac build, use **Platforms > Mac > Package Project** in the editor after selecting the desired configuration.

The project descriptor currently lists Mac as its target platform. Additional platforms should be added deliberately in `SurvivalGame1.uproject` and tested with their corresponding toolchains.

## Roadmap

Planned survival RPG systems include:

- Player attributes, progression, and equipment
- Resource gathering and crafting
- Inventory and item management
- Combat and enemy AI
- Survival needs and environmental challenges
- Quests, exploration, and world progression
- Save/load support

## License

No license has been specified for this repository yet. Until a license is added, all rights are reserved by the copyright holder.
