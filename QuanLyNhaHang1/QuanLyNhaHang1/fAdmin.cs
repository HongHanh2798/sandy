using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuanLyNhaHang1
{
    public partial class fAdmin : Form
    {
        public fAdmin()
        {
            InitializeComponent();
            LoadAccountList();
        }


    

        void LoadAccountList()
        {
            string connectionSTR = @"Data Source=.\SQLEXPRESS;Initial Catalog=QLCAFE;Integrated Security=True";  //Lấy từ Tools/Add data
            SqlConnection connection = new SqlConnection(connectionSTR);

            string query = "select * from dbo.Account";

            connection.Open();
            SqlCommand command = new SqlCommand(query, connection);  //truy vấn
            DataTable data = new DataTable();
            SqlDataAdapter adapter = new SqlDataAdapter(command); //trung gian lấy dữ liệu
            adapter.Fill(data);  //đổ dữ liệu vào data
            connection.Close();

            dtgvAccoumt.DataSource = data;
        }

        private void fAdmin_Load(object sender, EventArgs e)
        {

        }
    }
}
