package CalcApp;

import org.omg.PortableServer.POA;

/**
 * Generated from IDL interface "Calc".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public class CalcPOATie
	extends CalcPOA
{
	private CalcOperations _delegate;

	private POA _poa;
	public CalcPOATie(CalcOperations delegate)
	{
		_delegate = delegate;
	}
	public CalcPOATie(CalcOperations delegate, POA poa)
	{
		_delegate = delegate;
		_poa = poa;
	}
	public CalcApp.Calc _this()
	{
		org.omg.CORBA.Object __o = _this_object() ;
		CalcApp.Calc __r = CalcApp.CalcHelper.narrow(__o);
		return __r;
	}
	public CalcApp.Calc _this(org.omg.CORBA.ORB orb)
	{
		org.omg.CORBA.Object __o = _this_object(orb) ;
		CalcApp.Calc __r = CalcApp.CalcHelper.narrow(__o);
		return __r;
	}
	public CalcOperations _delegate()
	{
		return _delegate;
	}
	public void _delegate(CalcOperations delegate)
	{
		_delegate = delegate;
	}
	public POA _default_POA()
	{
		if (_poa != null)
		{
			return _poa;
		}
		return super._default_POA();
	}
	public float mul(float a, float b)
	{
		return _delegate.mul(a,b);
	}

	public float sum(float a, float b)
	{
		return _delegate.sum(a,b);
	}

	public float sub(float a, float b)
	{
		return _delegate.sub(a,b);
	}

	public float div(float a, float b) throws CalcApp.CalcPackage.DivisionByZero
	{
		return _delegate.div(a,b);
	}

}
