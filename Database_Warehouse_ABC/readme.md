

vba :

Function UDF_ABC(Data As Variant, MaxValue As Variant)

  Dim Step, ABC
  
  Step = MaxValue / 3
  
  If Data < Step Then ABC = "C"
            
  If Data >= Step And Data < (Step * 2) Then ABC = "B"
  
  If Data >= (Step * 2) Then ABC = "A"
  
  UDF_ABC = ABC   
  
End Function 

