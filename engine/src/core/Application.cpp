#include <core/Application.h>
#include <iostream>


namespace core {
    bool Application::init(const char* title, int w, int h) {
        if(!SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "[ENGINE::ERROR] SDL could not be initialized: " << SDL_GetError() << "\n";
            return false;
        } else std::cout << "[ENGINE::INFO] SDL initialized.\n";

        m_window = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
        if(!m_window) {
            std::cerr << "[ENGINE::ERROR] The window could not be initialized: " << SDL_GetError() << "\n";
            return false;
        } else std::cout << "[ENGINE::INFO] Window initialized.\n";

        m_renderer = SDL_CreateRenderer(m_window, nullptr);
        if(!m_renderer) {
            std::cerr << "[ENGINE::ERROR] The renderer could not be initialized: " << SDL_GetError() << "\n";
            return false;
        } else std::cout << "[ENGINE::INFO] Renderer initialized.\n";

        std::cout << "[ENGINE::INFO] Engine initialized successfully.\n";
        m_running = true;
        
        return true;
    }

    void Application::run() {
        const double dt = 1.0 / 60.0;
        double accumulator = 0.0;

        Uint64 current = SDL_GetTicksNS();
        
        while (m_running) {

            Uint64 newTime = SDL_GetTicksNS();
            double frameTime = (newTime - current) / 1'000'000'000.0;
            current = newTime;

            if (frameTime > 0.25) frameTime = 0.25;

            accumulator += frameTime;

            handleEvents();

            while (accumulator >= dt) {
                update(dt);
                accumulator -= dt;

                m_input.nextFrame();
            }

            render();
        }

        quit();
    }


    void Application::render() {
        SDL_SetRenderDrawColor(m_renderer, 120, 120, 120, 255);
        SDL_RenderClear(m_renderer);

        onRender();

        SDL_RenderPresent(m_renderer);
    }

    void Application::update(double dt) {
        onUpdate(dt);
    }

    void Application::handleEvents() {
        SDL_Event e;

        while(SDL_PollEvent(&e)) {
            m_input.handleEvent(e);

            switch(e.type) {
                case SDL_EVENT_QUIT:
                    m_running = false;
                break;

                default:
                    onHandleEvents(e);
                break;
            }
        }
    }

    void Application::quit() {
        onQuit();

        if(m_window) {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        if(m_renderer) {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = nullptr;
        }

        SDL_Quit();
    }
}