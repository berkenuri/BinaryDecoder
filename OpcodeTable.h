#ifndef __OPCODE_H__
#define __OPCODE_H__

using namespace std;

#include <iostream>
#include <string>


// Listing of all supported MIPS instructions
enum Opcode {
  ADD, 
  ADDI, 
  SUB,
  MULT,
  MFHI,
  SRL,
  SRA,
  SLTI,
  LW,
  J,
  BEQ,
  UNDEFINED
};

// Different types of MIPS encodings
enum InstType{
  RTYPE,
  ITYPE,
  JTYPE
};


/* This class represents templates for supported MIPS instructions.  For every supported
 * MIPS instruction, the OpcodeTable includes information about the opcode, expected
 * operands, and other fields.  
 */
class OpcodeTable {
 public:
// Initializes all the fields for every instruction in Opcode enum
  OpcodeTable();

  // Given a valid MIPS assembly mnemonic, returns an Opcode which represents a 
  // template for that instruction.
  Opcode getOpcode(string str);

  // Given a valid function and opcode field, returns an Opcode as a template for its
  // instruction
  Opcode getOpcode(string str1, string str2);

  // Given an Opcode, returns number of expected operands.
  int numOperands(Opcode o);

  // Given an Opcode, returns the position of RS field.  If field is not
  // appropriate for this Opcode, returns -1.
  int RSposition(Opcode o);

  // Given an Opcode, returns the position of RT  field.  If field is not
  // appropriate for this Opcode, returns -1.
  int RTposition(Opcode o);

  // Given an Opcode, returns the position of RD field.  If field is not
  // appropriate for this Opcode, returns -1.
  int RDposition(Opcode o);

  // Given an Opcode, returns the position of IMM field.  If field is not
  // appropriate for this Opcode, returns -1.
  int IMMposition(Opcode o);

  // Given an Opcode, returns true if instruction expects a label in the instruction.
  // See "J".
  bool isIMMLabel(Opcode o);

  string getName(Opcode o);

  // Given an Opcode, returns instruction type.
  InstType getInstType(Opcode o);

  // Given an Opcode, returns a string representing the binary encoding of the opcode
  // field.
  string getOpcodeField(Opcode o);

  // Given an Opcode, returns a string representing the binary encoding of the function
  // field.
  string getFunctField(Opcode o);


 private:
  // Provides information about how where to find values in a MIPS assembly
  // instruction and what pre-defined fields (opcode/funct) will be in
  // the encoding for the given instruction.
  struct OpcodeTableEntry{
    string name;
    int numOps;
    int rdPos;
    int rsPos;
    int rtPos;
    int immPos;
    bool immLabel;

    InstType instType;
    string op_field;
    string funct_field;

    // Creates an initial OpcodeTableEntry with default values
    OpcodeTableEntry(){
      numOps = 0; 
      rdPos = rsPos = rtPos = immPos = -1;
      immLabel = false;
    };
  };

  // The array of OpcodeTableEntries, one for each MIPS instruction supported
  OpcodeTableEntry myArray[UNDEFINED];


};


#endif
