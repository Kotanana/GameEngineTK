//
// Game.h
//

#pragma once

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <Model.h>

#include "StepTimer.h"
#include "DebugCamera.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

	Game();

	// Initialization and management
	void Initialize(HWND window, int width, int height);

	// Basic game loop
	void Tick();

	// Messages
	void OnActivated();
	void OnDeactivated();
	void OnSuspending();
	void OnResuming();
	void OnWindowSizeChanged(int width, int height);

	// Properties
	void GetDefaultSize(int& width, int& height) const;

private:

	void Update(DX::StepTimer const& timer);
	void Render();

	void Clear();
	void Present();

	void CreateDevice();
	void CreateResources();

	void OnDeviceLost();

	// Device resources.
	HWND                                            m_window;
	int                                             m_outputWidth;
	int                                             m_outputHeight;

	D3D_FEATURE_LEVEL                               m_featureLevel;
	Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

	Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
	Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

	// Rendering loop timer.
	DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_primitiveBatch;
	std::unique_ptr<DirectX::BasicEffect> m_basicEffect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
	std::unique_ptr<DirectX::CommonStates> m_states;

	//　ワールド行列
	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	//　デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugcamera;

	//　エフェクトファクトリー
	std::unique_ptr<DirectX::EffectFactory> m_factorySkydoom;
	std::unique_ptr<DirectX::EffectFactory> m_factoryGround;
	std::unique_ptr<DirectX::EffectFactory> m_factoryBall;

	//　モデル
	std::unique_ptr<DirectX::Model> m_modelSkydoom;
	std::unique_ptr<DirectX::Model> m_modelGround;
	std::unique_ptr<DirectX::Model> m_modelBall;

	//　球のワールド行列
	DirectX::SimpleMath::Matrix m_worldball;

	DirectX::SimpleMath::Matrix m_worldBall[20];
};