﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <memory>
#include <tchar.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
#include <functional>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

// DirectXTex
#include "../DirectXTex/DirectXTex.h"

// FMOD
#include "Library/FMOD/inc/fmod.hpp"
#pragma comment(lib,"Library/FMOD/fmod_vc.lib")

// ImGui
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_dx11.h"
#include "../ImGUI/imgui_impl_win32.h"

// DirectWrite
#include <d2d1_1.h>
#include <dwrite.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"dxguid.lib")

using namespace std;
using namespace DirectX;

#include "Types.h"

// Framework
#include "Framework/Device/Device.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

// Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManager.h"
#include "Framework/Render/RenderTarget.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/RectCollider.h"
#include "Framework/Collider/CircleCollider.h"

// Utillity
#include "Framework/Utillity/MathUtility.h"
#include "Framework/Utillity/InputManager.h"
#include "Framework/Utillity/Timer.h"
#include "Framework/Utillity/tinyxml2.h"
#include "Framework/Utillity/Audio.h"
#include "Framework/Utillity/BinaryWriter.h"
#include "Framework/Utillity/BinaryReader.h"
#include "Framework/Utillity/DataManager.h"
#include "Framework/Utillity/DirectWrite.h"

// Camera
#include "Framework/Camera/Camera.h"

// Texture
#include "Framework/Texture/SRV.h"
#include "Framework/Texture/SRVManager.h"
#include "Framework/Texture/SamplerState.h"
#include "Framework/Texture/BlendState.h"
#include "Framework/Texture/StateManager.h"

// Action
#include "Framework/Animation/Action.h"
#include "Framework/Animation/MyXML.h"

// Object
#include "Object/BagicObj/Quad.h"
#include "Object/BagicObj/Sprite.h"
#include "Object/BagicObj/Effect.h"
#include "Object/BagicObj/EffectManager.h"

// UI
#include "Object/UI/Button.h"
#include "Object/UI/Slider.h"
#include "Object/UI/Slot.h"
#include "Object/UI/ItemIcon.h"
#include "Object/UI/Inventory.h"
#include "Object/UI/Store.h"

// GameObj
#include "Object/GameObj/SolarSystem/Planet.h"

#include "Object/GameObj/Shooting/Bow_Bullet.h"
#include "Object/GameObj/Shooting/Bow_Bow.h"

#include "Object/GameObj/Zelda/Zelda.h"

#include "Object/GameObj/CupHead/Cup_Bullet.h"
#include "Object/GameObj/CupHead/Cup_Player.h"
#include "Object/GameObj/CupHead/Cup_Advanced_Player.h"
#include "Object/GameObj/CupHead/Cup_Monster.h"
#include "Object/GameObj/CupHead/Cup_Bg.h"

// Scene
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"

// Program
#include "Program/Program.h"