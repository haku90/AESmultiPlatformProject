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
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            userControl11.Stop();
        }

        private void uxKeyEncrypt_TextChanged(object sender, EventArgs e)
        {
            userControl11.Stop();
            userControl11.Key = uxKeyEncrypt.Text;
            
        }

        private void uxKeyForDecrypt_TextChanged(object sender, EventArgs e)
        {
            userControl11.Stop();
            userControl11.KeyForDecrypt = uxKeyForDecrypt.Text;
            
        }
    }
}
