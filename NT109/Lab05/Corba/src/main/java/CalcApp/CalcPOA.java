package CalcApp;


/**
 * Generated from IDL interface "Calc".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public abstract class CalcPOA
	extends org.omg.PortableServer.Servant
	implements org.omg.CORBA.portable.InvokeHandler, CalcApp.CalcOperations
{
	static private final java.util.HashMap<String,Integer> m_opsHash = new java.util.HashMap<String,Integer>();
	static
	{
		m_opsHash.put ( "mul", Integer.valueOf(0));
		m_opsHash.put ( "sum", Integer.valueOf(1));
		m_opsHash.put ( "sub", Integer.valueOf(2));
		m_opsHash.put ( "div", Integer.valueOf(3));
	}
	private String[] ids = {"IDL:CalcApp/Calc:1.0"};
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
	public org.omg.CORBA.portable.OutputStream _invoke(String method, org.omg.CORBA.portable.InputStream _input, org.omg.CORBA.portable.ResponseHandler handler)
		throws org.omg.CORBA.SystemException
	{
		org.omg.CORBA.portable.OutputStream _out = null;
		// do something
		// quick lookup of operation
		java.lang.Integer opsIndex = (java.lang.Integer)m_opsHash.get ( method );
		if ( null == opsIndex )
			throw new org.omg.CORBA.BAD_OPERATION(method + " not found");
		switch ( opsIndex.intValue() )
		{
			case 0: // mul
			{
				float _arg0=_input.read_float();
				float _arg1=_input.read_float();
				_out = handler.createReply();
				_out.write_float(mul(_arg0,_arg1));
				break;
			}
			case 1: // sum
			{
				float _arg0=_input.read_float();
				float _arg1=_input.read_float();
				_out = handler.createReply();
				_out.write_float(sum(_arg0,_arg1));
				break;
			}
			case 2: // sub
			{
				float _arg0=_input.read_float();
				float _arg1=_input.read_float();
				_out = handler.createReply();
				_out.write_float(sub(_arg0,_arg1));
				break;
			}
			case 3: // div
			{
			try
			{
				float _arg0=_input.read_float();
				float _arg1=_input.read_float();
				_out = handler.createReply();
				_out.write_float(div(_arg0,_arg1));
			}
			catch(CalcApp.CalcPackage.DivisionByZero _ex0)
			{
				_out = handler.createExceptionReply();
				CalcApp.CalcPackage.DivisionByZeroHelper.write(_out, _ex0);
			}
				break;
			}
		}
		return _out;
	}

	public String[] _all_interfaces(org.omg.PortableServer.POA poa, byte[] obj_id)
	{
		return ids;
	}
}
