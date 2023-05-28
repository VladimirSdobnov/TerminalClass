#include "Pred.h"

int main() {
	Department dep;
	Teacher teacher1(FIO("Ib", "Ib", "Ib"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher2(FIO("Ob", "Ob", "Ob"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher3(FIO("Pb", "Pb", "Pb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher4(FIO("Lb", "Lb", "Lb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher5(FIO("Jb", "Jb", "Jb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher6(FIO("Mb", "Mb", "Mb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher7(FIO("Nb", "Nb", "Nb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher8(FIO("Bb", "Ib", "Bb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher9(FIO("Vb", "Vb", "Vb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	Teacher teacher10(FIO("Ib", "Vb", "Jb"), "yrtyrt", 123.3, 12, Date(1, 10, 2003), 12, "ertytyr");
	dep.add_teacher(teacher1);
	dep.add_teacher(teacher2);
	dep.add_teacher(teacher4);
	dep.add_teacher(teacher5);
	dep.add_teacher(teacher6);
	dep.add_teacher(teacher7);
	dep.add_teacher(teacher8);
	dep.add_teacher(teacher9);
	dep.add_teacher(teacher3);
	dep.add_teacher(teacher10);
	dep.sort_fio();
}