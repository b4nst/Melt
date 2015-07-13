using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator
{
  class TextProgressBar
  {
    private int _size;
    public int Size
    {
      get { return _size; }
      set { _size = value; InitBar(); }
    }

    private int _maxValue;
    public int MaxValue
    {
      get { return _maxValue; }
      set { _maxValue = value; UpdateBar(); }
    }

    private int _currentValue;
    public int CurrentValue { 
      get { return _currentValue; } 
      set { _currentValue = value; UpdateBar(); } 
    }

    private float _onechunk { get { return (float)Size / (float)MaxValue; } }

    private void UpdateBar()
    {
      Console.CursorLeft = 0;

      //draw filled part
      for (int i = 0; i <= _onechunk * _currentValue; i++)
      {
        Console.BackgroundColor = ConsoleColor.Green;
        Console.Write(" ");
      }

      //draw unfilled part
      for (int i = Console.CursorLeft; i <= Size; i++)
      {
        Console.BackgroundColor = ConsoleColor.Gray;
        Console.Write(" ");
      }
      Console.BackgroundColor = ConsoleColor.Black;

      Console.CursorLeft += 4;
      Console.Write("{0} of {1}", _currentValue, _maxValue);
    }

    public void InitBar()
    {
      
    }
  }
}
