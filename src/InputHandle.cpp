#include "InputHandle.h"
#include <SDL_events.h>

void InputHandler::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			int mouseX = event.button.x;
			int mouseY = event.button.y;
			std::cout << "Mouse Button Down with x:"<<mouseX << " y:" << mouseY << std::endl;

			for (std::shared_ptr<InputObserver> observer : observers) {
				observer->OnMouseLeftClick(mouseX, mouseY);
			}
		}
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	case SDL_MOUSEMOTION:
		break;
	case SDL_KEYDOWN:
		break;
	default:
		break;
	}
}