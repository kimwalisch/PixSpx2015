#ifndef bit_table_dynamic_sum6_h
#define bit_table_dynamic_sum6_h

class bit_table_dynamic_sum6: public bit_table
{
private:
  long32 BASE;
  long32* partial_sums_array;
  long32 number_of_sums;
  long64 last_cnte;
  long64 origin; 
 protected:

  void fill();
  //void delete_words_array() {}; // yes, it does nothing!
public:
  long32 count(long32 x) const;
  void unset_bit(long32);
  ~bit_table_dynamic_sum6();
  bit_table_dynamic_sum6() {};
  bit_table_dynamic_sum6(long32 n) {
    create(n);
  }
  int init_counters() {
    return 1;
  }
  void create(long32);
  void create(long32, sieve_type st);
  void display(int n=0) const;
};
#endif
