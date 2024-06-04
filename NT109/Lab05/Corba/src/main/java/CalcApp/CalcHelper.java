package CalcApp;


/**
 * Generated from IDL interface "Calc".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public abstract class CalcHelper
{
	private volatile static org.omg.CORBA.TypeCode _type;
	public static org.omg.CORBA.TypeCode type ()
	{
		if (_type == null)
		{
			synchronized(CalcHelper.class)
			{
				if (_type == null)
				{
					_type = org.omg.CORBA.ORB.init().create_interface_tc("IDL:CalcApp/Calc:1.0", "Calc");
				}
			}
		}
		return _type;
	}

	public static void insert (final org.omg.CORBA.Any any, final CalcApp.Calc s)
	{
			any.insert_Object(s);
	}
	public static CalcApp.Calc extract(final org.omg.CORBA.Any any)
	{
		return narrow(any.extract_Object()) ;
	}
	public static String id()
	{
		return "IDL:CalcApp/Calc:1.0";
	}
	public static Calc read(final org.omg.CORBA.portable.InputStream in)
	{
		return narrow(in.read_Object(CalcApp._CalcStub.class));
	}
	public static void write(final org.omg.CORBA.portable.OutputStream _out, final CalcApp.Calc s)
	{
		_out.write_Object(s);
	}
	public static CalcApp.Calc narrow(final org.omg.CORBA.Object obj)
	{
		if (obj == null)
		{
			return null;
		}
		else if (obj instanceof CalcApp.Calc)
		{
			return (CalcApp.Calc)obj;
		}
		else if (obj._is_a("IDL:CalcApp/Calc:1.0"))
		{
			CalcApp._CalcStub stub;
			stub = new CalcApp._CalcStub();
			stub._set_delegate(((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate());
			return stub;
		}
		else
		{
			throw new org.omg.CORBA.BAD_PARAM("Narrow failed");
		}
	}
	public static CalcApp.Calc unchecked_narrow(final org.omg.CORBA.Object obj)
	{
		if (obj == null)
		{
			return null;
		}
		else if (obj instanceof CalcApp.Calc)
		{
			return (CalcApp.Calc)obj;
		}
		else
		{
			CalcApp._CalcStub stub;
			stub = new CalcApp._CalcStub();
			stub._set_delegate(((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate());
			return stub;
		}
	}
}
