using System;
using QuanLyNhaHang1.DTO;
using QuanLyNhaHang1.DAO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuanLyNhaHang1
{
    public partial class ThongTinCaNhan : Form
    {
   
        public ThongTinCaNhan(Account acc)
        {
            InitializeComponent();
            loginAccount = acc;
        }
        public Account LoginAccount
        {
            get { return loginAccount; }
            set { loginAccount = value; ChangeAccount(loginAccount); }
        }
        private Account loginAccount;
        void ChangeAccount(Account acc)
        {
            txbUserName.Text = LoginAccount.UserName;
            txbDisplayName.Text = LoginAccount.DisplayName;
       }
        void UpdateAccount()
        {
            string displayName = txbDisplayName.Text;
            string passWord = txbPassWord.Text;
            string newpass = txbNewPass.Text;
            string reenPass = txbReEnterPass.Text;
            string userName = txbUserName.Text;
            if(!newpass.Equals(reenPass))
            {
                MessageBox.Show("Mật khẩu nhập lại không khớp với mật khẩu mới");
            }
            else
            {
                if( AccountDAO.Instance.UpdateAccount(userName,displayName,passWord,newpass))
                {
                    MessageBox.Show("Cập nhập thành công");
                }
                else
                {
                    MessageBox.Show("Vui lòng điền đúng mật khẩu");
                }
            }
        }
        private void btnExti_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void ThongTinCaNhan_Load(object sender, EventArgs e)
        {

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            UpdateAccount();
        }
    }
}



