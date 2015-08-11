#include "BeesApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<BeesApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

BeesApp::BeesApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BeesApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BeesApp::associateSyntax(_syntax, _action_factory);
}

BeesApp::~BeesApp()
{
}

// External entry point for dynamic application loading
extern "C" void BeesApp__registerApps() { BeesApp::registerApps(); }
void
BeesApp::registerApps()
{
  registerApp(BeesApp);
}

// External entry point for dynamic object registration
extern "C" void BeesApp__registerObjects(Factory & factory) { BeesApp::registerObjects(factory); }
void
BeesApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BeesApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BeesApp::associateSyntax(syntax, action_factory); }
void
BeesApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
