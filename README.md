# 2D Game Engine

A modern C++ 2D game engine built with Entity-Component-System architecture, featuring Lua scripting integration and real-time rendering.

## 🎯 Overview

This 2D game engine demonstrates professional game development patterns through a clean ECS architecture implementation. Built from the ground up in C++17, it showcases how modern game engines organize complex systems while maintaining performance and extensibility.

The engine features a complete game loop, asset management, scripting capabilities, and modular component systems - making it an excellent foundation for 2D game development or educational exploration of game engine architecture.

## ✨ Features

- **Entity-Component-System Architecture** - Clean separation of data and behavior
- **Lua Scripting Integration** - Level scripting with Sol2 bindings
- **Real-time Rendering** - 60 FPS game loop with SDL2
- **Asset Management** - Centralized loading and caching system
- **Event System** - Decoupled communication between systems
- **Component Library** - Rich set of pre-built components
- **Debug Visualization** - Collision box rendering and system inspection
- **Dynamic Level Loading** - Runtime level switching and asset management

## 🏛️ Architecture

The engine follows the Entity-Component-System pattern:

- **Entities** - Unique identifiers representing game objects
- **Components** - Pure data structures (Position, Sprite, Health, etc.)
- **Systems** - Logic processors that operate on entities with specific components

```cpp
// Create an entity with components
auto player = registry->CreateEntity();
player.AddComponent<TransformComponent>(100, 100, 1.0, 1.0, 0.0);
player.AddComponent<SpriteComponent>("player-texture", 32, 32, 1);
player.AddComponent<KeyboardControlledComponent>(100, 100);
```

## 🚀 Quick Start

### Prerequisites
- C++17 compatible compiler (g++, clang++)
- SDL2 development libraries
- Lua development libraries

### Building

```bash
# Clone the repository
git clone [repository-url]
cd 2dgameengine

# Build the engine
make

# Run the demo
make run
```

## 🎮 Game Systems

### Core Components
- **TransformComponent** - Position, scale, and rotation
- **SpriteComponent** - Texture rendering with animation support
- **RigidBodyComponent** - Physics and velocity
- **BoxColliderComponent** - Collision detection
- **HealthComponent** - Health and damage system
- **ProjectileComponent** - Projectile behavior and lifecycle

### System Pipeline
1. **Input Processing** - Keyboard and controller input
2. **Movement System** - Entity position updates
3. **Collision System** - AABB collision detection and response
4. **Animation System** - Sprite frame animation
5. **Rendering System** - Draw calls and camera management
6. **GUI System** - Debug interface and HUD elements

## 📜 Lua Scripting

Levels are defined using Lua scripts, providing flexible game configuration:

```lua
-- Dynamic texture selection based on time
local current_hour = os.date("*t").hour
local map_texture = current_hour >= 9 and current_hour < 18 
    and "tilemap-day" or "tilemap-night"

Level = {
    assets = {
        { type = "texture", id = "player-texture", file = "./assets/player.png" },
        { type = "font", id = "main-font", file = "./assets/fonts/arial.ttf", size = 16 }
    },
    entities = {
        {
            components = {
                transform = { x = 100, y = 100, scale_x = 1.0, scale_y = 1.0 },
                sprite = { texture_asset_id = "player-texture", width = 32, height = 32 }
            }
        }
    }
}
```

### Script Bindings
- Entity creation and component attachment
- Asset loading and management
- Level configuration and initialization
- Runtime entity manipulation

## 🎨 Assets

The engine supports multiple asset types:
- **Textures** - PNG/JPG sprites and tilesets
- **Fonts** - TTF font files for text rendering
- **Audio** - WAV sound effects (via SDL2_mixer)
- **Tilemaps** - Custom .map format for level layouts

### Asset Loading
```cpp
assetStore->AddTexture(renderer, "player-texture", "./assets/player.png");
assetStore->AddFont("main-font", "./assets/fonts/arial.ttf", 16);
```

## 🔧 Development

### Technical Stack
- **C++17** - Modern C++ features and standards
- **SDL2** - Cross-platform graphics, input, and audio
- **SDL2_image** - Image loading (PNG, JPG)
- **SDL2_ttf** - TrueType font rendering
- **SDL2_mixer** - Audio playback
- **Lua 5.4** - Embedded scripting language
- **Sol2** - C++/Lua binding library
- **GLM** - OpenGL Mathematics library
- **Dear ImGui** - Immediate mode GUI for debugging

### Memory Management
- Smart pointers for automatic resource management
- Component pools for cache-friendly data access
- Entity recycling to minimize allocations
- RAII principles throughout the codebase

### Performance Considerations
- Fixed timestep game loop (60 FPS)
- Batch rendering for sprite drawing
- Spatial partitioning for collision detection
- Component pooling for memory efficiency

## 📁 Project Structure

```
2dgameengine/
├── src/
│   ├── Components/          # Component definitions
│   ├── Systems/             # System implementations
│   ├── ECS/                 # Entity-Component-System core
│   ├── Game/                # Main game loop and level loading
│   ├── AssetStore/          # Asset management
│   ├── EventBus/            # Event system
│   └── Logger/              # Logging utilities
├── assets/
│   ├── images/              # Sprite textures
│   ├── fonts/               # TrueType fonts
│   ├── scripts/             # Lua level definitions
│   ├── sounds/              # Audio files
│   └── tilemaps/            # Level maps and tilesets
├── libs/                    # Third-party libraries
└── Makefile                 # Build configuration
```

## 🔍 Debug Features

The engine includes comprehensive debugging tools:
- Collision box visualization
- Entity inspector with component details
- Performance metrics (FPS, entity count)
- Memory usage tracking
- System execution profiling

Toggle debug mode with the 'D' key during runtime.

## 🤝 Contributing

This project serves as an educational reference for game engine architecture. Key learning areas include:

- Entity-Component-System design patterns
- Game loop implementation and timing
- Memory-efficient component storage
- Scripting language integration
- Real-time rendering techniques

### Code Style
- Follow C++17 standards
- Use RAII for resource management
- Prefer composition over inheritance
- Maintain clear separation between data and logic

---

Built with modern C++ and a focus on clean architecture. Perfect for learning game engine fundamentals or as a foundation for 2D game projects.