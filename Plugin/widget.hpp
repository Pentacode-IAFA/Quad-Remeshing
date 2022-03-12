#pragma once

#include <QWidget>

#include <Engine/Data/Mesh.hpp>
#include <QuadRemeshing.hpp>

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
} // namespace Ra

namespace QuadRemeshing {

class MyWidget : public QWidget {
  Q_OBJECT

public:
  explicit MyWidget(Ra::Engine::RadiumEngine *engine,
                    Ra::Gui::SelectionManager *selectionManager,
                    QWidget *parent = 0);
  ~MyWidget();

signals:
  void computationRequested(QuadRemeshingParameter p);

private slots:
  void on__remeshButton_clicked();
  void on__step1Button_clicked();
  void on__step2Button_clicked();
  void on__step3Button_clicked();
  void on__step4Button_clicked();
  void on__step5Button_clicked();

  Ra::Engine::Data::Mesh *getSelectedMesh();

private:
  Ui::MyWidget *ui;

  Ra::Engine::RadiumEngine *m_engine{nullptr};
  Ra::Gui::SelectionManager *m_selectionManager{nullptr};
  QuadRemeshing::QuadRemesher *m_remesher;
};

} // namespace QuadRemeshing
