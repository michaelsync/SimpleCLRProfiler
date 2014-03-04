using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;


namespace AppStarter
{
    public partial class MainForm : Form
    {
        private readonly string SimpleProfilerDllName = "SimpleProfiler.dll";
        private readonly string SimpleProfilerGuid = "{68130646-C19E-459E-8BF4-5137ED7B3FD7}";

        public MainForm()
        {
            InitializeComponent();
        }

        private void pickAppButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "EXE files (*.exe)|*.exe";
            dialog.InitialDirectory = System.Environment.CurrentDirectory;

            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                appPathTextBox.Text = dialog.FileName;
            }
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            string exeToRun = appPathTextBox.Text;
            if (System.IO.File.Exists(exeToRun))
            {
                string profilerDll = Environment.CurrentDirectory + "\\" + SimpleProfilerDllName;

                ProcessStartInfo startupInfo = new ProcessStartInfo(exeToRun);
                setEnvironmentVariable(ref startupInfo, "COR_ENABLE_PROFILING", "1");
                setEnvironmentVariable(ref startupInfo, "COR_PROFILER", SimpleProfilerGuid);
                setEnvironmentVariable(ref startupInfo, "COR_PROFILER_PATH", profilerDll);

                startupInfo.UseShellExecute = false;
                Process p = Process.Start(startupInfo);
            }
        }

        private void setEnvironmentVariable(ref ProcessStartInfo startupInfo, string name, string value)
        {
            if (startupInfo.EnvironmentVariables.ContainsKey(name) == true)
                startupInfo.EnvironmentVariables[name] = value;
            else
                startupInfo.EnvironmentVariables.Add(name, value);
        }
    }
}
