using QuanLyNhaHang1.DTO;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuanLyNhaHang1
{
    public partial class GiaoDienChinh : Form
    {
        private Account loginAccount;
        public GiaoDienChinh(Account acc)
        {
            InitializeComponent();
            this.LoginAccount = acc;
        }

       public Account LoginAccount
        {
            get { return loginAccount; }
            set { loginAccount = value; /*ChangeAccount(loginAccount.Type);*/ }
        }

        private void GiaoDienChinh_Load(object sender, EventArgs e)
        {

        }
        void ChangeAccount(int type)
        {
            adminToolStripMenuItem.Enabled = type == 1;
            thôngTinTàiKhoảnToolStripMenuItem.Text += "(" + loginAccount.DisplayName + ")";
        }
   
        private void đăngXuấtToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void thôngTinCáNhânToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ThongTinCaNhan f = new ThongTinCaNhan(LoginAccount);
            f.ShowDialog();
        }

        private void adminToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }
    }
}
