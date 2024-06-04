package CalcApp;

/**
 * Generated from IDL interface "Calc".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public final class CalcHolder	implements org.omg.CORBA.portable.Streamable{
	 public Calc value;
	public CalcHolder()
	{
	}
	public CalcHolder (final Calc initial)
	{
		value = initial;
	}
	public org.omg.CORBA.TypeCode _type()
	{
		return CalcHelper.type();
	}
	public void _read (final org.omg.CORBA.portable.InputStream in)
	{
		value = CalcHelper.read (in);
	}
	public void _write (final org.omg.CORBA.portable.OutputStream _out)
	{
		CalcHelper.write (_out,value);
	}
}
