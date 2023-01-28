//#include "sdltemplate.h"
#include "addon.h"

#define PI 3.14
double SCREENWIDTH = 1920;//1600;//600;
double SCREENHEIGHT = 1080;//900;//600;

using namespace sdltemplate;
using namespace std;

entity player;
obj cursor;

void update() {
	goToMouse(&cursor);
//	std::cout << mouse.x << " " << mouse.y << " - " << cursor.dest.x << " " << cursor.dest.y << " " << cursor.dest.w << " " << cursor.dest.h << std::endl;
}

void render() {
	write("Game", 5, 5);
	write("hi", mouse.x, mouse.y);
	draw(&player);
	draw(&cursor);
}

void input() {
	if(keystates[SDL_SCANCODE_ESCAPE]) running=false;

	//player movement
	if(keystates[SDL_SCANCODE_W]) move(&player, 0, -1);
	if(keystates[SDL_SCANCODE_S]) move(&player, 0, 1);
	if(keystates[SDL_SCANCODE_A]) { move(&player, -1, 0); player.flipH = true; }
	if(keystates[SDL_SCANCODE_D]) { move(&player, 1, 0); player.flipH = false; }
}

void init() {
	cursor = createObj("assets/images/cursor.png", {0,0,40,40}, {0,0,10,10});
	player = createEnt("assets/images/player.png", {0,0,60,60}, {0,0,20,20}, 100, 100);
}

int main() {
	srand(time(NULL));
	sdl("Game", SCREENWIDTH, SCREENHEIGHT);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_ShowCursor(0);
	bkg = {143,155,252,255};
	loadFont("assets/fonts/Peepo.ttf", 16, {100, 200, 200, 255});

	init();

	while(running) {
		loop();

		update();
		render();
		input();
	}
	return 0;
}
