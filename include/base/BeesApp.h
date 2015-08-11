#ifndef BEESAPP_H
#define BEESAPP_H

#include "MooseApp.h"

class BeesApp;

template<>
InputParameters validParams<BeesApp>();

class BeesApp : public MooseApp
{
public:
  BeesApp(InputParameters parameters);
  virtual ~BeesApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BEESAPP_H */
