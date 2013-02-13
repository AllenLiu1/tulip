/**
 *
 * This file is part of Tulip (www.tulip-software.org)
 *
 * Authors: David Auber and the Tulip development Team
 * from LaBRI, University of Bordeaux 1 and Inria Bordeaux - Sud Ouest
 *
 * Tulip is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * Tulip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */

#include <tulip/PropertyTypes.h>
#include <tulip/Graph.h>

using namespace std;
using namespace tlp;

// GraphType
GraphType::RealType GraphType::undefinedValue() {
  return 0;
}

GraphType::RealType GraphType::defaultValue() {
  return 0;
}

void GraphType::write(ostream &oss, const RealType &v) {
  if (v)
    oss << v->getId();
}

bool GraphType::read(istream& iss, RealType& v) {
  unsigned long lv = 0;
  bool ok = iss >> lv;

  if (ok)
    v = (RealType) lv;
  else
    v = 0;

  return ok;
}

// EdgeSetType
void EdgeSetType::write(ostream& os, const RealType & v ) {
  os << '(';
  set<edge>::const_iterator it;

  for(it = v.begin() ; it != v.end() ; ++it)
    os << (*it).id << ' ';

  os << ')';
}

bool EdgeSetType::read(istream& is, RealType & v) {
  v.clear();
  char c  = ' ';
  bool ok;

  // go to first '('
  while((ok = (is >> c)) && isspace(c)) {}

  // for compatibility with older version (3.0)
  if (!ok)
    return true;

  if (c != '(')
    return false;

  edge e;

  for( ;; ) {
    if( !(is >> c) )
      return false;

    if( c == ')' )
      return true;

    is.unget();

    if( !(is >> e.id) )
      return false;

    v.insert( e );
  }
}

// DoubleType
double DoubleType::undefinedValue() {
  return -DBL_MAX;
}

double DoubleType::defaultValue() {
  return 0;
}

// add support for inf and -inf
bool DoubleType::read(istream& iss, double& v) {
  char c;
  char sign = 0;

  // go to first non space char
  while((iss >> c) && isspace(c)) {}

  if (c == '-' || c == '+') {
    sign = c;

    if (!(iss >> c))
      return false;
  }

  if (c == 'i') {
    // should be inf
    if (!(iss >> c) || (c != 'n') ||
        !(iss >> c) || (c != 'f'))
      return false;

    if (sign == '-')
      v = -numeric_limits<double>::infinity();
    else
      v = numeric_limits<double>::infinity();

    return true;
  }
  else {
    iss.unget();

    if (sign)
      iss.unget();
  }

  return iss >> v;
}

// FloatType
float FloatType::undefinedValue() {
  return -FLT_MAX;
}

float FloatType::defaultValue() {
  return 0;
}

// IntegerType
int IntegerType::undefinedValue() {
  return INT_MIN;
}

int IntegerType::defaultValue() {
  return 0;
}

// LongType
long LongType::undefinedValue() {
  return LONG_MIN;
}

long LongType::defaultValue() {
  return 0;
}

// UnsignedIntegerType
unsigned int UnsignedIntegerType::undefinedValue() {
  return UINT_MAX;
}

unsigned int UnsignedIntegerType::defaultValue() {
  return 0;
}

// BooleanType
bool BooleanType::undefinedValue() {
  return false;
}

bool BooleanType::defaultValue() {
  return false;
}

void BooleanType::write(ostream& os, const RealType &v) {
  if (v)
    os << "true";
  else
    os << "false";
}

bool BooleanType::read(istream& is, RealType & v) {
  char c = ' ';

  while((is >> c) && isspace(c)) {}

  c = ::tolower(c);

  if (c != 't' && c != 'f')
    return false;

  string s;

  if (c == 't') {
    s.append("true");
    v = true;
  }
  else {
    s.append("false");
    v = false;
  }

  for(unsigned int i = 1; i < s.size(); ++i) {
    if (!(is >> c))
      return false;

    c = ::tolower(c);

    if (c != s[i])
      return false;
  }

  return true;
}

// BooleanVectorType
void BooleanVectorType::write(ostream& os, const RealType & v) {
  os << '(';

  for( unsigned int i = 0 ; i < v.size() ; i++ ) {
    if (i)
      os << ", ";

    os << (v[i] ? "true" : "false");
  }

  os << ')';
}

bool BooleanVectorType::read(istream& is,  RealType & v) {
  v.clear();

  char c =' ';
  bool firstVal = true;

  // go to first '('
  while((is >> c) && isspace(c)) {}

  if (c != '(')
    return false;

  for(;;) {
    if( !(is >> c) )
      return false;

    if (isspace(c))
      continue;

    if(c == ')') {
      return true;
    }

    if (c == ',') {
      if (firstVal)
        return false;
    }
    else
      is.unget();

    bool val;

    if (!BooleanType::read(is, val))
      return false;

    v.push_back(val);
    firstVal = false;
  }
}

// LineType
bool LineType::read(istream& is, RealType& v) {
  v.clear();

  char c =' ';
  bool firstVal = true;
  bool dbqFound = false;

  // go to first '('
  // skip space chars
  while((is >> c) && isspace(c)) {}

  // value may have been enclosed by double quotes
  if (c == '"') {
    // open double quotes found
    dbqFound = true;

    // skip space chars
    while((is >> c) && isspace(c)) {}
  }

  if (c != '(')
    return false;

  for(;;) {
    if( !(is >> c) )
      return false;

    if (isspace(c))
      continue;

    if(c == ')') {
      if (dbqFound) {
        // expect it is the next non space char
        while((is >> c) && isspace(c)) {}

        if (c != '"')
          return false;
      }

      return true;
    }

    if (c == ',') {
      if (firstVal)
        return false;

      Coord val;

      if (!PointType::read(is, val))
        return false;

      v.push_back(val);
    }
    else {
      // , is not required between coords
      is.unget();
      Coord val;

      if (!PointType::read(is, val))
        return false;

      v.push_back(val);
      firstVal = false;
    }
  }
}

// PointType
Coord PointType::undefinedValue() {
  Coord tmp;
  tmp.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
  return tmp;
}

Coord PointType::defaultValue() {
  return Coord(0, 0, 0);
}

bool PointType::read(istream& is, RealType & v) {
  // value may have been enclosed by double quotes
  char c = ' ';
  bool ok;

  // skip spaces
  while((ok = (is >> c)) && isspace(c)) {}

  bool dbqFound = false;

  if (c == '"')
    // open double quotes found
    dbqFound = true;
  else
    is.unget();

  ok = is >> v;

  if (ok && dbqFound) {
    // look for the close double quote
    ok = is >> c;

    if (c != '"')
      return false;
  }

  return ok;
}

bool PointType::fromString( RealType & v, const string & s ) {
  istringstream iss(s);
  return iss >> v;
}

//
// SizeType
Size SizeType::undefinedValue() {
  return Size(-FLT_MAX,-FLT_MAX,-FLT_MAX);
}

Size SizeType::defaultValue() {
  return Size(1,1,0);
}

bool SizeType::read(istream& is, RealType & v) {
  // value may have been enclosed by double quotes
  char c = ' ';
  bool ok;

  // skip spaces
  while((ok = (is >> c)) && isspace(c)) {}

  bool dbqFound = false;

  if (c == '"')
    // open double quotes found
    dbqFound = true;
  else
    is.unget();

  ok = is >> v;

  if (ok && dbqFound) {
    // look for the close double quote
    ok = is >> c;

    if (c != '"')
      return false;
  }

  return ok;
}

bool SizeType::fromString( RealType & v, const string & s ) {
  istringstream iss(s);
  return iss >> v;
}

// StringType
string StringType::undefinedValue() {
  return string("");
}

string StringType::defaultValue() {
  return string("");
}

void StringType::write(ostream& os, const RealType & v ) {
  os << '"';

  for(char* str = (char *) v.c_str(); *str; ++str) {
    char c = *str;

    if (c == '\\' || c == '"')
      os << '\\';

    os << c;
  }

  os << '"';
}

string StringType::toString( const RealType & v ) {
  return v;
}

bool StringType::read(istream& is, RealType & v) {
  char c= ' ';

  // go to first '"'
  while((is >> c) && isspace(c)) {}

  if (c != '"')
    return false;

  bool bslashFound = false;
  string str;

  for(;;) {
    if ( !(is >> c) )
      return false;

    if (bslashFound) {
      str.push_back(c);
      bslashFound = false;
    }
    else {
      if (c == '\\')
        bslashFound = true;
      else {
        if (c == '"')
          break;

        str.push_back(c);
      }
    }
  }

  v = str;
  return true;
}

bool StringType::fromString( RealType & v, const string & s ) {
  v = s;
  return true;
}

// StringVectorType
void StringVectorType::write(ostream& os, const RealType & v) {
  os << '(';

  for( unsigned int i = 0 ; i < v.size() ; i++ ) {
    if (i)
      os << ", ";

    StringType::write(os, v[i]);
  }

  os << ')';
}

bool StringVectorType::read(istream& is, RealType & v) {
  v.clear();
  char c = ' ';

  // go to first '('
  while((is >> c) && isspace(c)) {}

  if (c != '(')
    return false;

  is.unsetf(ios_base::skipws);
  bool firstVal = true;
  bool sepFound = false;

  for( ;; ) {
    if( !(is >> c) )
      return false;

    if (isspace(c))
      continue;

    if( c == ')' ) {
      if (sepFound)
        return false;

      return true;
    }

    if (c == ',') {
      if (sepFound)
        return false;

      sepFound = true;
    }
    else {
      if ((firstVal || sepFound) && c == '"') {
        string str;
        is.unget();

        if (!StringType::read(is, str))
          return false;

        v.push_back(str);
        firstVal = false;
        sepFound = false;
      }
      else
        return false;
    }
  }
}

// ColorType
Color ColorType::undefinedValue() {
  return Color(255,255,255,255);
}

void ColorType::write(ostream& os, const RealType & v) {
  // add double quotes to ensure compatibility in gui tests
  os << '"' << v << '"';
}

string ColorType::toString( const RealType & v ) {
  ostringstream oss;
  oss << v;
  return oss.str();
}

bool ColorType::read(istream& is, RealType & v) {
  // value may have been enclosed by double quotes
  char c = ' ';
  bool ok;

  // skip spaces
  while((ok = (is >> c)) && isspace(c)) {}

  bool dbqFound = false;

  if (c == '"')
    // open double quotes found
    dbqFound = true;
  else
    is.unget();

  ok = is >> v;

  if (ok && dbqFound) {
    // look for the close double quote
    ok = is >> c;

    if (c != '"')
      return false;
  }

  return ok;
}

bool ColorType::fromString( RealType & v, const string & s ) {
  istringstream iss(s);
  return iss >> v;
}

// some special serializers
struct DataSetTypeSerializer :public TypedDataSerializer<DataSet> {
  DataSetTypeSerializer():TypedDataSerializer<DataSet>("DataSet") {}

  DataTypeSerializer* clone() const {
    return new DataSetTypeSerializer();
  }

  void write(ostream& os, const DataSet& ds) {
    DataSet::write(os, ds);
  }

  bool read(istream& is, DataSet& ds) {
    return DataSet::read(is, ds);
  }

  bool setData(tlp::DataSet&, const string&, const string&) {
    // no sense
    return false;
  }
};

// some special serializers
struct NodeTypeSerializer : public TypedDataSerializer<node> {

  KnownTypeSerializer<UnsignedIntegerType> *uintSerializer;

  NodeTypeSerializer():TypedDataSerializer<node>("node") {
      uintSerializer = new KnownTypeSerializer<UnsignedIntegerType>("");
  }

  ~NodeTypeSerializer() {
      delete uintSerializer;
  }

  DataTypeSerializer* clone() const {
    return new NodeTypeSerializer();
  }

  void write(ostream& os, const node& n) {
    uintSerializer->write(os, n.id);
  }

  bool read(istream& is, node& n) {
    return uintSerializer->read(is, n.id);
  }

  bool setData(tlp::DataSet&, const string&, const string&) {
    // no sense
    return false;
  }
};

struct NodeVectorTypeSerializer : public TypedDataSerializer<vector<node> >{

  KnownTypeSerializer<UnsignedIntegerVectorType> *uintVecSerializer;

  NodeVectorTypeSerializer():TypedDataSerializer<vector<node> >("nodes") {
      uintVecSerializer = new KnownTypeSerializer<UnsignedIntegerVectorType>("");
  }

  ~NodeVectorTypeSerializer() {
      delete uintVecSerializer;
  }

  DataTypeSerializer* clone() const {
    return new NodeVectorTypeSerializer();
  }

  void write(ostream& os, const vector<node>& vn) {
      uintVecSerializer->write(os, reinterpret_cast<const vector<unsigned int> &>(vn));
  }

  bool read(istream& is, vector<node>& vn) {
    return uintVecSerializer->read(is, reinterpret_cast<vector<unsigned int> &>(vn));
  }

  bool setData(tlp::DataSet&, const string&, const string&) {
    // no sense
    return false;
  }
};

struct EdgeTypeSerializer : public TypedDataSerializer<edge> {

  KnownTypeSerializer<UnsignedIntegerType> *uintSerializer;

  EdgeTypeSerializer():TypedDataSerializer<edge>("edge") {
      uintSerializer = new KnownTypeSerializer<UnsignedIntegerType>("");
  }

  ~EdgeTypeSerializer() {
      delete uintSerializer;
  }

  DataTypeSerializer* clone() const {
    return new EdgeTypeSerializer();
  }

  void write(ostream& os, const edge& e) {
    uintSerializer->write(os, e.id);
  }

  bool read(istream& is, edge& e) {
    return uintSerializer->read(is, e.id);
  }

  bool setData(tlp::DataSet&, const string&, const string&) {
    // no sense
    return false;
  }
};

struct EdgeVectorTypeSerializer : public TypedDataSerializer<vector<edge> >{

  KnownTypeSerializer<UnsignedIntegerVectorType> *uintVecSerializer;

  EdgeVectorTypeSerializer():TypedDataSerializer<vector<edge> >("edges") {
      uintVecSerializer = new KnownTypeSerializer<UnsignedIntegerVectorType>("");
  }

  ~EdgeVectorTypeSerializer() {
      delete uintVecSerializer;
  }

  DataTypeSerializer* clone() const {
    return new EdgeVectorTypeSerializer();
  }

  void write(ostream& os, const vector<edge>& ve) {
      uintVecSerializer->write(os, reinterpret_cast<const vector<unsigned int> &>(ve));
  }

  bool read(istream& is, vector<edge>& ve) {
    return uintVecSerializer->read(is, reinterpret_cast<vector<unsigned int> &>(ve));
  }

  bool setData(tlp::DataSet&, const string&, const string&) {
    // no sense
    return false;
  }

};

void tlp::initTypeSerializers() {
  DataSet::registerDataTypeSerializer<EdgeSetType::RealType>(KnownTypeSerializer<EdgeSetType>("edgeset"));

  DataSet::registerDataTypeSerializer<DoubleType::RealType>(KnownTypeSerializer<DoubleType>("double"));

  DataSet::registerDataTypeSerializer<FloatType::RealType>(KnownTypeSerializer<FloatType>("float"));

  DataSet::registerDataTypeSerializer<BooleanType::RealType>(KnownTypeSerializer<BooleanType>("bool"));

  DataSet::registerDataTypeSerializer<IntegerType::RealType>(KnownTypeSerializer<IntegerType>("int"));

  DataSet::registerDataTypeSerializer<UnsignedIntegerType::RealType>(KnownTypeSerializer<UnsignedIntegerType>("uint"));

  DataSet::registerDataTypeSerializer<LongType::RealType>(KnownTypeSerializer<LongType>("long"));

  DataSet::registerDataTypeSerializer<ColorType::RealType>(KnownTypeSerializer<ColorType>("color"));

  DataSet::registerDataTypeSerializer<PointType::RealType>(KnownTypeSerializer<PointType>("coord"));

  DataSet::registerDataTypeSerializer<StringType::RealType>(KnownTypeSerializer<StringType>("string"));

  DataSet::registerDataTypeSerializer<DoubleVectorType::RealType>(KnownTypeSerializer<DoubleVectorType>("doublevector"));

  DataSet::registerDataTypeSerializer<BooleanVectorType::RealType>(KnownTypeSerializer<BooleanVectorType>("boolvector"));

  DataSet::registerDataTypeSerializer<IntegerVectorType::RealType>(KnownTypeSerializer<IntegerVectorType>("intvector"));

  DataSet::registerDataTypeSerializer<ColorVectorType::RealType>(KnownTypeSerializer<ColorVectorType>("colorvector"));

  DataSet::registerDataTypeSerializer<LineType::RealType>(KnownTypeSerializer<LineType>("coordvector"));

  DataSet::registerDataTypeSerializer<StringVectorType::RealType>(KnownTypeSerializer<StringVectorType>("stringvector"));

  DataSet::registerDataTypeSerializer<DataSet>(DataSetTypeSerializer());

  DataSet::registerDataTypeSerializer<node>(NodeTypeSerializer());

  DataSet::registerDataTypeSerializer<vector<node> >(NodeVectorTypeSerializer());

  DataSet::registerDataTypeSerializer<edge>(EdgeTypeSerializer());

  DataSet::registerDataTypeSerializer<vector<edge> >(EdgeVectorTypeSerializer());

}
