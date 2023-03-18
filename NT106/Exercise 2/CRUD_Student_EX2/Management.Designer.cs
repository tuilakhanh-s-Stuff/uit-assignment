namespace CRUD_Student_EX2
{
	partial class Management
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		///  Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			label1 = new Label();
			labelID = new Label();
			labelName = new Label();
			labelBIRTH = new Label();
			labelADDRESS = new Label();
			inputID = new TextBox();
			inputNAME = new TextBox();
			inputBIRTH = new TextBox();
			inputADDRESS = new TextBox();
			btnAdd = new Button();
			btnDelete = new Button();
			btnEdit = new Button();
			studentView = new DataGridView();
			ID = new DataGridViewTextBoxColumn();
			NAME = new DataGridViewTextBoxColumn();
			BIRTH = new DataGridViewTextBoxColumn();
			ADDRESS = new DataGridViewTextBoxColumn();
			((System.ComponentModel.ISupportInitialize)studentView).BeginInit();
			SuspendLayout();
			// 
			// label1
			// 
			label1.Anchor = AnchorStyles.Top;
			label1.AutoSize = true;
			label1.Font = new Font("Open Sans", 25F, FontStyle.Bold, GraphicsUnit.Point);
			label1.Location = new Point(442, 27);
			label1.Name = "label1";
			label1.Size = new Size(465, 72);
			label1.TabIndex = 0;
			label1.Text = "Quản Lý Học Sinh";
			label1.TextAlign = ContentAlignment.MiddleCenter;
			// 
			// labelID
			// 
			labelID.AutoSize = true;
			labelID.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			labelID.Location = new Point(108, 150);
			labelID.Name = "labelID";
			labelID.Size = new Size(235, 40);
			labelID.TabIndex = 1;
			labelID.Text = "Mã Số Sinh Viên";
			// 
			// labelName
			// 
			labelName.AutoSize = true;
			labelName.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			labelName.Location = new Point(109, 211);
			labelName.Name = "labelName";
			labelName.Size = new Size(155, 40);
			labelName.TabIndex = 2;
			labelName.Text = "Họ Và Tên";
			// 
			// labelBIRTH
			// 
			labelBIRTH.AutoSize = true;
			labelBIRTH.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			labelBIRTH.Location = new Point(108, 274);
			labelBIRTH.Name = "labelBIRTH";
			labelBIRTH.Size = new Size(156, 40);
			labelBIRTH.TabIndex = 3;
			labelBIRTH.Text = "Ngày Sinh";
			// 
			// labelADDRESS
			// 
			labelADDRESS.AutoSize = true;
			labelADDRESS.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			labelADDRESS.Location = new Point(108, 340);
			labelADDRESS.Name = "labelADDRESS";
			labelADDRESS.Size = new Size(116, 40);
			labelADDRESS.TabIndex = 4;
			labelADDRESS.Text = "Địa Chỉ";
			// 
			// inputID
			// 
			inputID.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			inputID.Location = new Point(394, 150);
			inputID.Name = "inputID";
			inputID.Size = new Size(737, 46);
			inputID.TabIndex = 5;
			// 
			// inputNAME
			// 
			inputNAME.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			inputNAME.Location = new Point(394, 211);
			inputNAME.Name = "inputNAME";
			inputNAME.Size = new Size(737, 46);
			inputNAME.TabIndex = 6;
			// 
			// inputBIRTH
			// 
			inputBIRTH.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			inputBIRTH.Location = new Point(394, 274);
			inputBIRTH.Name = "inputBIRTH";
			inputBIRTH.Size = new Size(737, 46);
			inputBIRTH.TabIndex = 7;
			// 
			// inputADDRESS
			// 
			inputADDRESS.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			inputADDRESS.Location = new Point(394, 340);
			inputADDRESS.Name = "inputADDRESS";
			inputADDRESS.Size = new Size(737, 46);
			inputADDRESS.TabIndex = 8;
			// 
			// btnAdd
			// 
			btnAdd.AutoSize = true;
			btnAdd.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			btnAdd.Location = new Point(369, 433);
			btnAdd.Name = "btnAdd";
			btnAdd.Size = new Size(138, 50);
			btnAdd.TabIndex = 9;
			btnAdd.Text = "Thêm";
			btnAdd.UseVisualStyleBackColor = true;
			btnAdd.Click += btnAdd_Click;
			// 
			// btnDelete
			// 
			btnDelete.AutoSize = true;
			btnDelete.Enabled = false;
			btnDelete.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			btnDelete.Location = new Point(860, 435);
			btnDelete.Name = "btnDelete";
			btnDelete.Size = new Size(138, 50);
			btnDelete.TabIndex = 10;
			btnDelete.Text = "Xoá";
			btnDelete.UseVisualStyleBackColor = true;
			btnDelete.Click += btnDelete_Click;
			// 
			// btnEdit
			// 
			btnEdit.AutoSize = true;
			btnEdit.Enabled = false;
			btnEdit.Font = new Font("Open Sans", 14F, FontStyle.Bold, GraphicsUnit.Point);
			btnEdit.Location = new Point(618, 434);
			btnEdit.Name = "btnEdit";
			btnEdit.Size = new Size(138, 50);
			btnEdit.TabIndex = 11;
			btnEdit.Text = "Sửa";
			btnEdit.TextAlign = ContentAlignment.BottomCenter;
			btnEdit.UseVisualStyleBackColor = true;
			btnEdit.Click += btnEdit_Click;
			// 
			// studentView
			// 
			studentView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
			studentView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			studentView.Columns.AddRange(new DataGridViewColumn[] { ID, NAME, BIRTH, ADDRESS });
			studentView.Location = new Point(12, 530);
			studentView.Name = "studentView";
			studentView.RowHeadersWidth = 62;
			studentView.RowTemplate.Height = 33;
			studentView.Size = new Size(1294, 300);
			studentView.TabIndex = 12;
			studentView.CellClick += studentView_CellClick;
			studentView.DefaultCellStyle.Font = new Font("Open Sans", 10F, GraphicsUnit.Point);
			// 
			// ID
			// 
			ID.DataPropertyName = "ID";
			ID.HeaderText = "Mã Sinh Viên";
			ID.MinimumWidth = 8;
			ID.Name = "ID";
			// 
			// NAME
			// 
			NAME.DataPropertyName = "NAME";
			NAME.HeaderText = "Họ Và Tên";
			NAME.MinimumWidth = 8;
			NAME.Name = "NAME";
			// 
			// BIRTH
			// 
			BIRTH.DataPropertyName = "BIRTH";
			BIRTH.HeaderText = "Ngày Sinh";
			BIRTH.MinimumWidth = 8;
			BIRTH.Name = "BIRTH";
			// 
			// ADDRESS
			// 
			ADDRESS.DataPropertyName = "ADDRESS";
			ADDRESS.HeaderText = "Địa Chỉ";
			ADDRESS.MinimumWidth = 8;
			ADDRESS.Name = "ADDRESS";
			// 
			// Form1
			// 
			AutoScaleDimensions = new SizeF(10F, 25F);
			AutoScaleMode = AutoScaleMode.Font;
			ClientSize = new Size(1318, 842);
			Controls.Add(studentView);
			Controls.Add(btnEdit);
			Controls.Add(btnDelete);
			Controls.Add(btnAdd);
			Controls.Add(inputADDRESS);
			Controls.Add(inputBIRTH);
			Controls.Add(inputNAME);
			Controls.Add(inputID);
			Controls.Add(labelADDRESS);
			Controls.Add(labelBIRTH);
			Controls.Add(labelName);
			Controls.Add(labelID);
			Controls.Add(label1);
			Name = "Form1";
			Text = "Form1";
			FormClosing += Form1_FormClosing;
			Load += Form1_Load;
			((System.ComponentModel.ISupportInitialize)studentView).EndInit();
			ResumeLayout(false);
			PerformLayout();
		}

		#endregion

		private Label label1;
		private Label labelID;
		private Label labelName;
		private Label labelBIRTH;
		private Label labelADDRESS;
		private TextBox inputID;
		private TextBox inputNAME;
		private TextBox inputBIRTH;
		private TextBox inputADDRESS;
		private Button btnAdd;
		private Button btnDelete;
		private Button btnEdit;
		private DataGridView studentView;
		private DataGridViewTextBoxColumn ID;
		private DataGridViewTextBoxColumn NAME;
		private DataGridViewTextBoxColumn BIRTH;
		private DataGridViewTextBoxColumn ADDRESS;
	}
}