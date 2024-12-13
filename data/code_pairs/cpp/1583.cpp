#ifndef OUTPUT_FILES_H
#define OUTPUT_FILES_H

constexpr int MAX_OUTPUT_FILES = 10;

void ofh_close_unit(int unit);
void ofh_close_all_units();

#endif // OUTPUT_FILES_H