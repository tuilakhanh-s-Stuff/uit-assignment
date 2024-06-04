package CalcApp.CalcPackage;


/**
 * Generated from IDL exception "DivisionByZero".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public abstract class DivisionByZeroHelper
{
	private volatile static org.omg.CORBA.TypeCode _type;
	public static org.omg.CORBA.TypeCode type ()
	{
		if (_type == null)
		{
			synchronized(DivisionByZeroHelper.class)
			{
				if (_type == null)
				{
					_type = org.omg.CORBA.ORB.init().create_exception_tc(CalcApp.CalcPackage.DivisionByZeroHelper.id(),"DivisionByZero",new org.omg.CORBA.StructMember[0]);
				}
			}
		}
		return _type;
	}

	public static void insert (final org.omg.CORBA.Any any, final CalcApp.CalcPackage.DivisionByZero s)
	{
		any.type(type());
		write( any.create_output_stream(),s);
	}

	public static CalcApp.CalcPackage.DivisionByZero extract (final org.omg.CORBA.Any any)
	{
		org.omg.CORBA.portable.InputStream in = any.create_input_stream();
		try
		{
			return read (in);
		}
		finally
		{
			try
			{
				in.close();
			}
			catch (java.io.IOException e)
			{
			throw new RuntimeException("Unexpected exception " + e.toString() );
			}
		}
	}

	public static String id()
	{
		return "IDL:CalcApp/Calc/DivisionByZero:1.0";
	}
	public static CalcApp.CalcPackage.DivisionByZero read (final org.omg.CORBA.portable.InputStream in)
	{
		String id = in.read_string();
		if (!id.equals(id())) throw new org.omg.CORBA.MARSHAL("wrong id: " + id);
		final CalcApp.CalcPackage.DivisionByZero result = new CalcApp.CalcPackage.DivisionByZero(id);
		return result;
	}
	public static void write (final org.omg.CORBA.portable.OutputStream out, final CalcApp.CalcPackage.DivisionByZero s)
	{
		out.write_string(id());
	}
}
