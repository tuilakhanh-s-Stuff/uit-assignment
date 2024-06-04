package CalcApp.CalcPackage;

/**
 * Generated from IDL exception "DivisionByZero".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public final class DivisionByZeroHolder
	implements org.omg.CORBA.portable.Streamable
{
	public CalcApp.CalcPackage.DivisionByZero value;

	public DivisionByZeroHolder ()
	{
	}
	public DivisionByZeroHolder(final CalcApp.CalcPackage.DivisionByZero initial)
	{
		value = initial;
	}
	public org.omg.CORBA.TypeCode _type ()
	{
		return CalcApp.CalcPackage.DivisionByZeroHelper.type ();
	}
	public void _read(final org.omg.CORBA.portable.InputStream _in)
	{
		value = CalcApp.CalcPackage.DivisionByZeroHelper.read(_in);
	}
	public void _write(final org.omg.CORBA.portable.OutputStream _out)
	{
		CalcApp.CalcPackage.DivisionByZeroHelper.write(_out, value);
	}
}
