#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "AbstractView.hpp"

namespace View
{
    class ConsoleView final: AbstractView{
    public:
        explicit ConsoleView(View::AbstractView* view);
        void render(const Utils::Params& params) override;
        void isRunning() const;
    };
}

#endif //CONSOLEVIEW_H
