#include <MeshProcessingPlugin.hpp>

#include <Gui/Viewer/Viewer.hpp>
namespace QuadRemeshing {

void QuadRemshingPlugin::registerPlugin(const Ra::Plugins::Context &context) {
  m_engine = context.m_engine;
  m_selectionManager = context.m_selectionManager;

  connect(this, &QuadRemshingPlugin::askForUpdate, &context,
          &Ra::Plugins::Context::askForUpdate);

  //   RadiumMeshProcessing::RadiumMeshProcessingWelcome(
  //       "Initializing RadiumMeshProcessing library.");
  //   RadiumMeshProcessing::initializeRadiumMeshProcessing();
  //   RadiumMeshProcessing::RadiumMeshProcessingWelcome("Registering plugin.");
}
bool QuadRemshingPlugin::doAddWidget(QString &name) {
  name = "Quad remeshing";
  m_widget = new MyWidget(m_engine, m_selectionManager);
  return true;
}
QWidget *QuadRemshingPlugin::getWidget() { return m_widget; }
} // namespace QuadRemeshing
