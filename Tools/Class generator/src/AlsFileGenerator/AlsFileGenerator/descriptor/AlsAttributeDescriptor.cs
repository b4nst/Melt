using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator.descriptor
{
  [Serializable()]
  public class AlsAttributeDescriptor
  {
    public String Type { get; set; }

    public String TagName { get; set; }

    public String AttributeName { get; set; }
  }
}
