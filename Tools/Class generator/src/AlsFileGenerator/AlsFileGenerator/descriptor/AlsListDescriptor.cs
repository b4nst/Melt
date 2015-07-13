using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator.descriptor
{
  [Serializable()]
  public class AlsListDescriptor : AlsAttributeDescriptor
  {
    public List<ListPossibleValue> PossibleContent { get; set; }
  }
}
