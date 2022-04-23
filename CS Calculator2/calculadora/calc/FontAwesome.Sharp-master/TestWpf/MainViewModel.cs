﻿using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Input;
using FontAwesome.Sharp;

namespace TestWpf
{
    public class MainViewModel : INotifyPropertyChanged
    {
        private bool _isSpinning = true;

        public MainViewModel()
        {
            OpenCommand = new DelegateCommand(DoOpen);
            PlayCommand = new DelegateCommand(DoPlay);
            ToggleSpinCommand = new DelegateCommand(ToggleSpin);
        }

        public IconChar Icon { get; set; }
        public ICommand OpenCommand { get; }
        public ICommand PlayCommand { get; }
        public ICommand ToggleSpinCommand { get; }

        public bool IsSpinning
        {
            get => _isSpinning;
            set
            {
                if (_isSpinning == value) return;
                _isSpinning = value;
                OnPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;


        private void DoOpen()
        {
            MessageBox.Show("Clicked Open", "Info");
        }

        private void DoPlay()
        {
            MessageBox.Show("Clicked Play", "Info");
        }

        private void ToggleSpin()
        {
            IsSpinning = !IsSpinning;
        }

        private void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}