#include "Skydome.h"
#include <numbers>

void Skydome::Initialize(Model* model, ViewProjection* viewProjection) {

	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	viewProjection_ = viewProjection;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / -2.0f;
}

void Skydome::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	worldTransform_.rotation_.y += 0.008f; // 回転速度は調整可能
	// 行列計算
	worldTransform_.UpdateMatrix();
}

void Skydome::Draw() { model_->Draw(worldTransform_, *viewProjection_); }
