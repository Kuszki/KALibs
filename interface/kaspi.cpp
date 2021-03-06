#include "kaspi.hpp"

KASpi::KASpi(MODE Mode)
{
	switch (Mode)
	{
		case MASTER:

			KAPin::SetOutputMode(KAPin::PORT_B, 0b00101100);
			KAPin::SetInputMode(KAPin::PORT_B, 0b00010000);

			SPSR = 0b00000001;
			SPCR = 0b01010000;

		break;
		case SLAVE:

			KAPin::SetInputMode(KAPin::PORT_B, 0b00101100);
			KAPin::SetOutputMode(KAPin::PORT_B, 0b00010000);

			SPCR = 0b11000000;

		break;
	}
}

KASpi::~KASpi(void)
{
	SPSR = SPCR = 0;

	KAPin::SetInputMode(KAPin::PORT_B, 0b00111100);
}

void KASpi::Select(KAPin::PORT Port, char Mask)
{
	KAPin::GetPort(Port) &= ~Mask;
}

void KASpi::Unselect(KAPin::PORT Port, char Mask)
{
	KAPin::GetPort(Port) |= Mask;
}

void KASpi::Send(char Char)
{
	SPDR = Char;

	while (!(SPSR & 0b10000000));
}

void KASpi::Send(const char* String)
{
	while (*String) Send(*String++);
}

void KASpi::Send(const void* Data, size_t Size)
{
	register const char* String = (char*) Data;

	while (Size--) Send(*String++);
}

void KASpi::SendPgmChar(unsigned Adress)
{
	Send(__LPM(Adress));
}

void KASpi::SendPgmString(unsigned Adress)
{
	while (char c = __LPM(Adress++)) Send(c);
}

void KASpi::SendPgmData(unsigned Adress, size_t Size)
{
	while (Size--) Send(__LPM(Adress++));
}

char KASpi::Recv(void)
{
	SPDR = 0;

	while (!(SPSR & 0b10000000));

	return SPDR;
}

void KASpi::Recv(void* Data, size_t Size)
{
	register char* ptData = (char*) Data;

	while (Size)
	{
		*ptData = Recv();

		++ptData;
		--Size;
	}
}

KASpi& KASpi::operator << (char Char)
{
	Send(Char);

	return *this;
}

KASpi& KASpi::operator << (const char* String)
{
	Send(String);

	return *this;
}

KASpi& KASpi::operator << (const void* Adress)
{
	SendPgmString((unsigned) Adress);

	return *this;
}

KASpi& KASpi::operator >> (char& Char)
{
	Char = Recv();

	return *this;
}
