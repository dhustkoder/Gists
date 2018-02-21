

class Test  {
	constructor() 
	{
		console.log('test contructor');
		this.testingVar = 'Hello Modafoka';
		this.testMethod = this._testMethod.bind(this);
	}

	_testMethod()
	{
		this.testingVar = 'Testing Var Changed';
	}
	
	printTestingVar()
	{
		console.log(this.testingVar);
	}

}


class FunCaller {
	constructor(fun)
	{
		this.fun = fun;
	}

	callFun()
	{
		this.fun();
	}
}


test = new Test();
funCaller = new FunCaller(test.testMethod);
funCaller.callFun();
test.printTestingVar();


