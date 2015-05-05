using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace InterfaceWebCam
{
    public partial class uxKey : Form
    {
        public uxKey()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            userControl11.Start();
            userControl12.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            userControl11.Stop();
            userControl12.Stop();
        }

        private void uxKeyEncrypt_TextChanged(object sender, EventArgs e)
        {
            userControl12.Key = uxKeyEncrypt.Text;
            
        }

        private void uxKeyForDecrypt_TextChanged(object sender, EventArgs e)
        {
            userControl12.KeyForDecrypt = uxKeyForDecrypt.Text;
            
        }

        private void uxKey_Load(object sender, EventArgs e)
        {
            userControl12.Key = uxKeyEncrypt.Text;
            userControl12.KeyForDecrypt = uxKeyForDecrypt.Text;
        }
    }
}
