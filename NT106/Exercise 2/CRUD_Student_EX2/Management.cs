using System.Data;

namespace CRUD_Student_EX2
{
	public partial class Management : Form
	{
		private SQLConnector DataBase = new SQLConnector();
		private int _ID = 0;
		public Management()
		{
			InitializeComponent();
			if (!this.DataBase.Connect())
				MessageBox.Show("Please Configure Your Connection");
		}
		private void Form1_Load(object sender, EventArgs e)
		{
			if (this.DataBase.SqlConnection.State == ConnectionState.Open)
			{
				LoadStudent();
			}
			else
				Application.Exit();
		}

		private void LoadStudent()
		{
			DataBase.Command.CommandType = CommandType.Text;
			DataBase.Command.CommandText = "SELECT ID, NAME, FORMAT(BIRTH,'dd/MM/yyyy') AS BIRTH, ADDRESS FROM STUDENT ";
			DataBase.SqlDataReader = DataBase.Command.ExecuteReader();
			DataTable DataTable = new DataTable();
			DataTable.Clear();
			DataTable.Load(DataBase.SqlDataReader);
			studentView.DataSource = DataTable;
		}

		private void SetEmptyValue()
		{
			inputID.Text = string.Empty;
			inputNAME.Text = string.Empty;
			inputBIRTH.Text = string.Empty;
			inputADDRESS.Text = string.Empty;
			btnDelete.Enabled = false;
			btnEdit.Enabled = false;
		}

		private void studentView_CellClick(object sender, DataGridViewCellEventArgs e)
		{
			try
			{
				if (studentView.CurrentRow.Index != -1)
				{
					_ID = Convert.ToInt32(studentView.CurrentRow.Cells[0].Value.ToString());
					inputID.Text = _ID.ToString();
					inputNAME.Text = studentView.CurrentRow.Cells[1].Value.ToString();
					inputBIRTH.Text = studentView.CurrentRow.Cells[2].Value.ToString();
					inputADDRESS.Text = studentView.CurrentRow.Cells[3].Value.ToString();
					btnDelete.Enabled = true;
					btnEdit.Enabled = true;
				}
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void btnAdd_Click(object sender, EventArgs e)
		{
			try
			{
				DataBase.Command.CommandType = CommandType.Text;
				DataBase.Command.CommandText = "INSERT INTO STUDENT(ID, NAME, BIRTH, ADDRESS) " +
					"VALUES(" + int.Parse(inputID.Text) + ", '" + inputNAME.Text + "', '" + inputBIRTH.Text + "', '" + inputADDRESS.Text + "')";
				DataBase.Command.ExecuteNonQuery();
				LoadStudent();
			}
			catch
			{
				MessageBox.Show("Thêm thất bại", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return;
			}
			MessageBox.Show("Thêm thành công", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Information);
			SetEmptyValue();
		}

		private void btnDelete_Click(object sender, EventArgs e)
		{
			try
			{
				DataBase.Command.CommandType = CommandType.Text;
				DataBase.Command.CommandText = "DELETE FROM STUDENT WHERE ID = '" + int.Parse(inputID.Text) + "'";
				DataBase.Command.ExecuteNonQuery();
				LoadStudent();
			}
			catch
			{
				MessageBox.Show("Xóa thất bại", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return;
			}
			MessageBox.Show("Xóa thành công", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Information);
			SetEmptyValue();
		}

		private void btnEdit_Click(object sender, EventArgs e)
		{
			try
			{
				DataBase.Command.CommandType = CommandType.Text;
				DataBase.Command.CommandText = "UPDATE STUDENT SET ID = " + int.Parse(inputID.Text) +
					", NAME = '" + inputNAME.Text + "', BIRTH =  '" + inputBIRTH.Text + "', ADDRESS = '" + inputADDRESS.Text + "' WHERE ID = '" + int.Parse(inputID.Text) + "'";
				DataBase.Command.ExecuteNonQuery();
				LoadStudent();
			}
			catch
			{
				MessageBox.Show("Sửa thất bại", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return;
			}
			MessageBox.Show("Sửa thành công", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Information);
			SetEmptyValue();
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			DataBase.Disconnect();
		}
	}
}