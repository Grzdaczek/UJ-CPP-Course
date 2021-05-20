#ifndef _SNAPSHOT_H
#define _SNAPSHOT_H

class AbstractSnapshot {
	public:
	virtual void restore() = 0;
	
	protected:
	void* _target;
	// AbstractSnapshot();
};

template<typename T>
class AbstractSnapshotable {
	public:
	virtual T const* save() = 0;
	virtual void restore(T const* s) = 0;
};

#endif // _SNAPSHOT_H