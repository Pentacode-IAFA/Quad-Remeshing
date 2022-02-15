#pragma once

#include <QWidget>

#include <RadiumMeshProcessing.hpp>

namespace Ui {
class MyWidget;
}

namespace Ra {
namespace Engine {
class RadiumEngine;
}
namespace Gui {
class SelectionManager;
}
}

namespace RadiumMeshProcessing {

class MyWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit MyWidget( Ra::Engine::RadiumEngine* engine, Ra::Gui::SelectionManager* selectionManager, QWidget* parent = 0 );
    ~MyWidget();

  signals:
    void computationRequested( ProcessingParameter p );

  private slots:
    void on__runButton_clicked();

  private:
    Ui::MyWidget* ui;

    Ra::Engine::RadiumEngine* m_engine {nullptr};
    Ra::Gui::SelectionManager* m_selectionManager { nullptr };
};

} // namespace RadiumMeshProcessing

