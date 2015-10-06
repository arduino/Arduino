///
/// @file		Mailbox.h
/// @brief		RTOS Mailbox, part of the Galaxia Library Suite
/// @details	RTOS Mailbox as C++ object for Energia MT
/// @n
/// @n @b		Project Energia MT 0101E0016
///
/// @author		Energia, base
/// @author		Rei Vilo, enhancements
///
/// @date		Jun 14, 2015 09:53
/// @version	104
///
/// @see        SYS/BIOS (TI-RTOS Kernel) v6.41 User's Guide (spruex3o)
///             http://www.ti.com/lit/pdf/spruex3
///

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Mailbox.h>
#include <ti/sysbios/BIOS.h>

#ifndef Mailbox_h
#define Mailbox_h

///
/// @warning    Header and code for template class need to be on the same unique file.
///             I guess it isn't a bug, but a feature :/
/// @see        http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2003/n1426.pdf
///

///
/// @brief      RTOS Mailbox as an object
/// @details    The RTOS Mailbox is encapsulated as a C++ object for easier use
/// @warning    Messages must be of type typename used in declaration
/// @note       Only a single task can pend on an Mailbox object at a time.
///
template <typename mailboxType> class Mailbox
{
private:
    Mailbox_Handle MailboxHandle;
    Mailbox_Params mboxParams;
    
    static xdc_UInt MailboxId;
    xdc_UInt Mailbox_Id_number;
    
public:
    ///
    /// @brief      Define the mailbox
    /// @warning    Specify typename between brackets in declaration.
    /// @code       Mailbox<typename> myMailbox;
    /// @endcode
    ///
    Mailbox();
    
    ///
    /// @brief      Create the mailbox
    /// @param		number number of messages of the mailbox, default = 16
    ///
    void begin(uint16_t number = 16);

    ///
    /// @brief      Post a message to the mailbox
    /// @param      message message to be posted on the mailbox
    /// @param      timeout default = BIOS_WAIT_FOREVER, BIOS_NO_WAIT
    /// @return     true if message posted, false otherwise
    /// @note       When using BIOS_NO_WAIT, message isn't posted if mailbox is full.
    ///             Check returned bool for result.
    /// @warning    Message must be of type typename.
    ///
    bool post(mailboxType &message, uint16_t timeout = BIOS_WAIT_FOREVER);

    ///
    /// @brief      Wait for a message from the mailbox
    /// @param      message message read from mailbox when available
    /// @warning    Message must be of type typename.
    ///
    void waitFor(mailboxType &message);
    
    ///
    /// @brief		Available messages to be read
    /// @return		number of available messages on the mailbox to be read
    /// @note       0 = no messages available
    ///
    uint16_t available();
};


template <typename mailboxType> Mailbox<mailboxType>::Mailbox()
{
    ;
}

template <typename mailboxType> void Mailbox<mailboxType>::begin(uint16_t number)
{
    Error_Block eb;
    Error_init(&eb);
    
    MailboxHandle = Mailbox_create(sizeof(mailboxType), number, NULL, &eb);
    if (MailboxHandle == NULL)
    {
        System_abort("Mailbox create failed");
    }
}

template <typename mailboxType> void Mailbox<mailboxType>::waitFor(mailboxType &message)
{
    Mailbox_pend(MailboxHandle, &message, BIOS_WAIT_FOREVER);
}

template <typename mailboxType> bool Mailbox<mailboxType>::post(mailboxType &message, uint16_t timeout)
{
     return Mailbox_post(MailboxHandle, &message, timeout);
}

template <typename mailboxType> uint16_t Mailbox<mailboxType>::available()
{
    return Mailbox_getNumPendingMsgs(MailboxHandle);
}

#endif
