#include <iostream>
#include <PureMVC/PureMVC.hpp>


using PureMVC::Interfaces::IFacade;
using PureMVC::Patterns::Facade;
using PureMVC::Interfaces::IController;
using PureMVC::Core::Controller;
using PureMVC::Interfaces::IModel;
using PureMVC::Core::Model;

int main(int argc, char *argv[])
{
	IFacade &facade1 = Facade::getInstance("Facade1");
	IFacade &facade2 = Facade::getInstance("Facade2");
	IController& controller1 = Controller::getInstance("Controller1");
	IController& controller2 = Controller::getInstance("Controller2");
	IController& controller3 = Controller::getInstance("Controller3");
	IModel& model1 = Model::getInstance("Model1");
	std::cout << "puremvc_app" << std::endl;
	return 0;
}