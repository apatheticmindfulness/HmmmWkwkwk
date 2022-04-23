#include "mieayam_window.h"
#include "mieayam_basic_graphics.h"
#include "mieayam_time.h"

int main()
{
	// Inisialisasi Pustaka MieAyam
	MieAyam_Init();

	// Definisikan atribut pada window
	mieayam_window_attributes window = { };
	window.width = 800;
	window.height = 600;
	window.title = "HmmmWkwkwk";

	mieayam_basic_graphics_attributes graphics = { };
	graphics.width = 800;
	graphics.height = 600;
	graphics.windowIndex = 0;
	graphics.bitCount = 32;

	// Buat window
	MieAyam_CreateWindow(&window, 1);
	MieAyam_InitBasicGraphics(&graphics, 1);

	MieAyam_TimeInit();

	// Tampilkan window, 0 untuk single window
	MieAyam_ShowWindow(0);

	// Jalankan proses per frame
	while (MieAyam_RunProccess())
	{
		MieAyam_RenderStart(0);
		MieAyam_CleanBackground(MIEAYAM_COLOR_CORNFLOWERBLUE);

		if (MieAyam_MouseLeftIsPressed())
		{
			for (int y = 100; y < MieAyam_GetMouseY(); y++)
			{
				for (int x = 100; x < MieAyam_GetMouseX(); x++)
				{
					MieAyam_SetPixel(x, y, MIEAYAM_COLOR_PURPLE);
				}
			}
		}

		MieAyam_RenderEnd();


		MieAyam_TimeCount();
	}
}