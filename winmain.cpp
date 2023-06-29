//ディレクター:茂木恵大
//サブディレクター:柏木春人
#include"DxLib.h"
#include"player.h"
#include"playershot.h"
#include"enemy.h"
#include"ishit.h"
#include"game.h"
#include"scene.h"

void init(void);
void update(void);
void draw(void);

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();

	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		update();

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
void init(void)
{
	initscene();
	initplayer();
	initplayershot();
	initenemy();
	initgame();
}
void update(void)
{
	updatescene();
	updateplayer();
	updateplayershot();
	updateenemy();
	updateishit();
	updategame();
	draw();
}
void draw(void)
{
	drawscene();
	drawplayer();
	drawplayershot();
	drawenemy();
	drawgame();
}