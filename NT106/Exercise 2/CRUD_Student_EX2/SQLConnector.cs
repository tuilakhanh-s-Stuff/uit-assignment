using System.Data.SqlClient;
using System.Data;

namespace CRUD_Student_EX2
{
	class SQLConnector
	{
		private const string _serverName = "localhost";
		private const string _databaseName = "StudentManagement";
		private const bool _integratedSecurity = true;

		public SqlConnection SqlConnection { get; set; }
		public SqlCommand Command { get; set; }
		public SqlDataReader? SqlDataReader { get; set; }

		public SQLConnector()
		{
			var builder = new SqlConnectionStringBuilder();
			builder["Data Source"] = _serverName;
			builder["Integrated Security"] = _integratedSecurity;
			builder["Database"] = _databaseName;

			this.SqlConnection = new SqlConnection(builder.ToString());

			this.Command = new SqlCommand();
			this.Command.Connection = this.SqlConnection;
		}


		public bool Connect()
		{
			if (this.SqlConnection.State == ConnectionState.Closed || this.SqlConnection.State == ConnectionState.Broken)
			{
				try 
				{ 
					this.SqlConnection.Open(); 
				}
				catch 
				{ 
					return false; 
				}
			}
			return true;
		}
		public bool Disconnect()
		{
			if (this.SqlConnection.State == ConnectionState.Closed)
			{
				return false;
			}
			SqlConnection.Close();
			return true;
		}
	}
}
