#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
    public:
        OpCommand() : Command() {}; 
        OpCommand(double value) {
            root = new Op(value); 
        }; 
};

class AddCommand : public Command {
	//AddCommand Code Here
    public: 
        AddCommand() : Command() {};        //plz refer to lab5 for notes
        AddCommand(Command* Opr1, double Opr2) {
            Base* val = new Op(Opr2); 
            root = new Add(Opr1->get_root(), val); 
        };
};

class SubCommand : public Command {
	//SubCommand Code Here
    public:
        SubCommand() : Command() {}; 
        SubCommand(Command* Opr1, double Opr2) {
            Base* val = new Op(Opr2); 
            root = new Sub(Opr1->get_root(), val); 
        };
};

class MultCommand : public Command {
	//MultCommand Code Here
    public: 
        MultCommand() : Command() {}; 
        MultCommand(Command* Opr1, double Opr2) {
            Base* val = new Op(Opr2); 
            root = new Mult(Opr1->get_root(), val); 
        };
};

class SqrCommand : public Command {
	//SqrCommand Code Here
    public: 
        SqrCommand() : Command() {}; 
        SqrCommand(Command* Opr1) {
            root = new Sqr(Opr1->get_root()); 
        };
};

#endif //__COMMAND_CLASS__
