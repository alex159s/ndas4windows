�PNG

   IHDR           �Tg�   tIME�
8�\�T   	pHYs    ��~�   0PLTE�����                                    B�[   tRNS�� ��A   �IDATxڅ�� !D't 6�t@쿷Žd=�|h|�tl <��
z]b~ b=n�
:u�� T4qH��0����@�b����������x~���ی��+9��������!���5
4X�)��ؚ�� y3=Kض�s    IEND�B`�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   //
    //  Type and size of this record (must be FAT_NTC_IRP_CONTEXT)
    //

    NODE_TYPE_CODE NodeTypeCode;
    NODE_BYTE_SIZE NodeByteSize;

    //
    //  This structure is used for posting to the Ex worker threads.
    //

    WORK_QUEUE_ITEM WorkQueueItem;

    //
    //  A pointer to the originating Irp.
    //

    PIRP OriginatingIrp;

    //
    //  Originating Device (required for workque algorithms)
    //

    PDEVICE_OBJECT RealDevice;

    //
    //  Originating Vcb (required for exception handling)
    //  On mounts, this will be set before any exceptions
    //  indicating corruption can be thrown.
    //

    PVCB Vcb;

    //
    //  Major and minor function codes copied from the Irp
    //

    UCHAR MajorFunction;
    UCHAR MinorFunction;

    //
    //  The following fields indicate if we can wait/block for a resource
    //  or I/O, if we are to do everything write through, and if this
    //  entry into the Fsd is a recursive call.
    //

    UCHAR PinCount;

    ULONG Flags;

    //
    //  The following field contains the NTSTATUS value used when we are
    //  unwinding due to an exception
    //

    NTSTATUS ExceptionStatus;

    //
    //  The following context block is used for non-cached Io
    //

    struct _FAT_IO_CONTEXT *FatIoContext;

    //
    //  For a abnormal termination unwinding this field contains the Bcbs
    //  that are kept pinned until the Irp is completed.
    //

    REPINNED_BCBS Repinned;

} IRP_CONTEXT;
typedef IRP_CONTEXT *PIRP_CONTEXT;

#define IRP_CONTEXT_FLAG_DISABLE_DIRTY   (0x00000001)
#define IRP_CONTEXT_FLAG_WAIT            (0x00000002)
#define IRP_CONTEXT_FLAG_WRITE_THROUGH   (0x00000004)
#define IRP_CONTEXT_FLAG_FLOPPY          (0x00000008)
#define IRP_CONTEXT_FLAG_RECURSIVE_CALL  (0x00000010)
#define IRP_CONTEXT_FLAG_DISABLE_POPUPS  (0x00000020)
#define IRP_CONTEXT_FLAG_DEFERRED_WRITE  (0x00000040)
#define IRP_CONTEXT_FLAG_VERIFY_READ     (0x00000080)
#define IRP_CONTEXT_STACK_IO_CONTEXT     (0x00000100)
#define IRP_CONTEXT_FLAG_IN_FSP          (0x00000200)
#define IRP_CONTEXT_FLAG_USER_IO         (0x00000400)       // for performance counters
#define IRP_CONTEXT_FLAG_DISABLE_RAISE   (0x00000800)
#define IRP_CONTEXT_FLAG_PARENT_BY_CHILD (0x80000000)


//
//  Context structure for non-cached I/O calls.  Most of these fields
//  are actually only required for the Read/Write Multiple routines, but
//  the caller must allocate one as a local variable anyway before knowing
//  whether there are multiple requests are not.  Therefore, a single
//  structure is used for simplicity.
//

typedef struct _FAT_IO_CONTEXT {

    //
    //  These two field are used for multiple run Io
    //

    LONG IrpCount;
    PIRP MasterIrp;

    union {

        //
        //  This element handles the asychronous non-cached Io
        //

        struct {
            PERESOURCE Resource;
            ERESOURCE_THREAD ResourceThreadId;
            ULONG RequestedByteCount;
            PFILE_OBJECT FileObject;
            PNON_PAGED_FCB NonPagedFcb;
        } Async;

        //
        //  and this element the sycnrhonous non-cached Io
        //

        KEVENT SyncEvent;

    } Wait;

} FAT_IO_CONTEXT;

typedef FAT_IO_CONTEXT *PFAT_IO_CONTEXT;

//
//  An array of these structures is passed to FatMultipleAsync describing
//  a set of runs to execute in parallel.
//

typedef struct _IO_RUNS {

    LBO Lbo;
    VBO Vbo;
    ULONG Offset;
    ULONG ByteCount;
    PIRP SavedIrp;

} IO_RUN;

typedef IO_RUN *PIO_RUN;

//
//  This structure is used by FatDeleteDirent to preserve the first cluster
//  and file size info for undelete utilities.
//

typedef struct _DELETE_CONTEXT {

    ULONG FileSize;
    ULONG FirstClusterOfFile;

} DELETE_CONTEXT;

typedef DELETE_CONTEXT *PDELETE_CONTEXT;

//
//  This record is used with to set a flush to go off one second after the
//  first write.  This is an attempt to keep the red ligh
Fontname=
Italic=0
LeftIndent=300
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=30

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-35]
BackgroundColor=536870911
Bold=1
ClearPreviousStyle=0
Color=255
Fontname=
Italic=0
None=0
ParaAttributeOnly=0
Size=8
StrikeOut=0
Underline=0

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-4]
Alignment=0
BackgroundColor=536870911
Bold=0
ClearPreviousStyle=1
Color=0
FirstIndent=0
Fontname=
Italic=0
LeftIndent=0
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=30

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-5]
Alignment=0
BackgroundColor=536870911
Bold=1
ClearPreviousStyle=1
Color=0
FirstIndent=0
Fontname=
Italic=0
LeftIndent=0
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=60

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-6]
Alignment=0
BackgroundColor=536870911
Bold=1
ClearPreviousStyle=1
Color=0
FirstIndent=0
Fontname=
Italic=0
LeftIndent=0
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=60

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-7]
Alignment=0
BackgroundColor=536870911
Bold=0
ClearPreviousStyle=1
Color=0
FirstIndent=0
Fontname=
Italic=0
LeftIndent=0
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=30

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Elements\-8]
Alignment=0
BackgroundColor=536870911
Bold=0
ClearPreviousStyle=1
Color=0
FirstIndent=-300
Fontname=
Italic=0
LeftIndent=500
None=0
ParaAttributeOnly=0
RightIndent=0
Size=9
StrikeOut=0
Underline=0
VSpaceAfter=30
VSpaceBefore=30

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Filter Images]
Count=0

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Flags]
FlagSeparatorString=' | '

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Formatting Options]
CurrentScheme=

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\General Build Options]
ShowDocumentation=1

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\Help Project]
CompressHelp=1
CreateContentFile=1
CreateDualHelpSupportFiles=1
CreateMapFiles=1
CustomHelpProjectFile=
HelpProjectFileAutomatic=1
WindowColorAddInfoContent=16777215
WindowColorAddInfoTop=65535
WindowColorBodySourceContent=16777215
WindowColorBodySourceTop=14540253
WindowColorHierarchyContent=16777215
WindowColorHierarchyTop=16777215
WindowColorNavContent=14876671
WindowColorNavTop=12632256
WindowColorSeeAlsoContent=16777215
WindowColorSeeAlsoTop=16777215
WindowColorTopicContent=16777215
WindowColorTopicTop=16777215
WindowNameAddInfo=ADDINFO
WindowNameBodySource=SOURCE
WindowNameHierarchy=
WindowNameNav=NAV
WindowNameSeeAlso=
WindowNameTopic=MAIN
WindowPositionAddInfo=420,45,563,366
WindowPositionBodySource=420,45,563,366
WindowPositionHierarchy=
WindowPositionNav=200,410,220,503
WindowPositionSeeAlso=
WindowPositionTopic=420,410,563,503

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\OutputNavigation]
NavigationLegendOptions=2

[{C81B476F-5DE3-416C-A73A-9674B8ECC110}\OutputNavigation\Main]
Count=32
DisplayText_0=Class Helpers
DisplayText_1=Classes
DisplayText_10=Friends
DisplayText_11=Functions
DisplayText_12=Group
DisplayText_13=Interfaces
DisplayText_14=Libraries
DisplayText_15=Macros
DisplayText_16=Members
DisplayText_17=Methods
DisplayText_18=Modules
DisplayText_19=Namespaces
DisplayText_2=CoClasses
DisplayText_20=Nested Types
DisplayText_21=Objects
DisplayText_22=Packages
DisplayText_23=Properties
DisplayText_24=Records
DisplayText_25=Structs
DisplayText_26=Templates
DisplayText_27=Topics
DisplayText_28=Types
DisplayText_29=Unions
DisplayText_3=Constants
DisplayText_30=Units
DisplayText_31=Variables
DisplayText_4=Data Members
DisplayText_5=Enumerations
DisplayText_6=Events
DisplayText_7=Fields
DisplayText_8=File
DisplayText_9=Files
ID_0=23
ID_1=23
ID_10=23
ID_11=23
ID_12=23
ID_13=23ibuteContext( IrpContext, &LocalContext );

        //
        //  Initialize the attribute context on each trip through the loop.
        //

        NtfsInitializeAttributeContext( &LocalContext );

        //
        //  Now there should be a single attribute record, so look it up and delete it.
        //

        FoundAttribute = NtfsLookupAttributeByName( IrpContext,
                                                    Fcb,
                                                    &Fcb->FileReference,
                                                    Scb->AttributeTypeCode,
                                                    &Scb->AttributeName,
                                                    NULL,
                                                    TRUE,
                                                    &LocalContext );

        //
        //  If this stream is subject to quota, make sure the quota has been enlarged.
        //

        NtfsDeleteAttributeRecord( IrpContext,
                                   Fcb,
                                   (DELETE_LOG_OPERATION |
                                    DELETE_RELEASE_FILE_RECORD |
                                    DELETE_RELEASE_ALLOCATION),
                                   &LocalContext );

        SetFlag( Scb->ScbState, SCB_STATE_ATTRIBUTE_DELETED );

    } finally {

        NtfsReleaseFcb( IrpContext, Fcb );

        NtfsCleanupAttributeContext( IrpContext, &LocalContext );
    }

    return;
}


NTFSAPI
LONGLONG
NtOfsQueryLength (
    IN PSCB Scb
    )

/*++

Routine Description:

    This routine may be called to query the Length (FileSize) of an attribute.

Arguments:

    Scb - Supplies an Scb as the previously returned handle for this attribute.

    Length - Returns the current Length of the attribute.

Return Value:

    None (Deleting a nonexistant index is benign).

--*/

{
    LONGLONG Length;

    PAGED_CODE();

    ExAcquireFastMutex( Scb->Header.FastMutex );
    Length = Scb->Header.FileSize.QuadPart;
    ExReleaseFastMutex( Scb->Header.FastMutex );
    return Length;
}


NTFSAPI
VOID
NtOfsSetLength (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN LONGLONG Length
    )

/*++

Routine Description:

    This routine may be called to set the Length (FileSize) of an attribute.

Arguments:

    Scb - Supplies an Scb as the previously returned handle for this attribute.

    Length - Supplies the new Length for the attribute.

Return Value:

    None (Deleting a nonexistant index is benign).

--*/

{
    ATTRIBUTE_ENUMERATION_CONTEXT AttrContext;

    PFILE_OBJECT FileObject = Scb->FileObject;
    PFCB Fcb = Scb->Fcb;
    PVCB Vcb = Scb->Vcb;
    BOOLEAN DoingIoAtEof = FALSE;
    BOOLEAN Truncating = FALSE;
    BOOLEAN CleanupAttrContext = FALSE;

    ASSERT_IRP_CONTEXT( IrpContext );
    ASSERT_SCB( Scb );
    ASSERT( NtfsIsExclusiveScb( Scb ));

    ASSERT(FileObject != NULL);

    PAGED_CODE();

    try {

        //
        //  If this is a resident attribute we will try to keep it resident.
        //

        if (FlagOn( Scb->ScbState, SCB_STATE_ATTRIBUTE_RESIDENT )) {

            //
            //  If the new file size is larger than a file record then convert
            //  to non-resident and use the non-resident code below.  Otherwise
            //  call ChangeAttributeValue which may also convert to nonresident.
            //

            NtfsInitializeAttributeContext( &AttrContext );
            CleanupAttrContext = TRUE;

            NtfsLookupAttributeForScb( IrpContext,
                                       Scb,
                                       NULL,
                                       &AttrContext );

            //
            //  Either convert or change the attribute value.
            //

            if (Length >= Scb->Vcb->BytesPerFileRecordSegment) {

                NtfsConvertToNonresident( IrpContext,
                                          Fcb,
                                          NtfsFoundAttribute( &AttrContext ),
                                          FALSE,
                                          &AttrContext );

            } else {

                ULONG AttributeOffset;

                //
                //  We are sometimes called by MM during a create section, so
                //  for right now the best way we have of detecting a create
                //  section is whether or not the requestor mode is kernel.
                //

                if ((ULONG)Length > Scb->Header.FileSize.LowPart) {

                    AttributeOffset = Scb->Header.FileSize.LowPart;

                } else {

                    AttributeOffset = (ULONG) Length;
                }

                //
                //  ****TEMP  Ideally we would do this simple case by hand.
                //

                NtfsChangeAttributeValue( IrpContext,
                                          Fcb,
                                          AttributeOffset,
                                          NULL,
                                          (ULONG)Length - AttributeOffset,
                                          TRUE,
                                          FALSE,
                                          FALSE,
                                          FALSE,
                                          &AttrContext );

                ExAcquireFastMutex( Scb->Header.FastMutex );

                Scb->Header.FileSize.QuadPart = Length;

                //
                //  If the file went non-resident, then the allocation size in
                //  the Scb is correct.  Otherwise we quad-align the new file size.
                //

                if (FlagOn( Scb->ScbState, SCB_STATE_ATTRIBUTE_RESIDENT )) {

                    Scb->Header.AllocationSize.LowPart = QuadAlign( Scb->Header.FileSize.LowPart );
                    if (Scb->Header.ValidDataLength.QuadPart != MAXLONGLONG) {
                        Scb->Header.ValidDataLength.QuadPart = Length;
                    }

                    Scb->TotalAllocated = Scb->Header.AllocationSize.QuadPart;

                } else {

                    SetFlag( Scb->ScbState, SCB_STATE_CHECK_ATTRIBUTE_SIZE );
                }

                ExReleaseFastMutex( Scb->Header.FastMutex );

                //
                //  Now update Cc.
                //

                CcSetFileSizes( FileObject, (PCC_FILE_SIZES)&Scb->Header.AllocationSize );

                //
                //  ****TEMP****  This hack is awaiting our actually doing this change
                //                in CcSetFileSizes.
                //

                *((PLONGLONG)(Scb->NonpagedScb->SegmentObject.SharedCacheMap) + 5) = Length;

                leave;
            }
        }

        //
        //  Nonresident path
        //
        //  Now determine where the new file size lines up with the
        //  current file layout.  The two cases we need to consider are
        //  where the new file size is less than the current file size and
        //  valid data length, in which case we need to shrink them.
        //  Or we new file size is greater than the current allocation,
        //  in which case we need to extend the allocation to match the
        //  new file size.
        //

        if (Length > Scb->Header.AllocationSize.QuadPart) {

            LONGLONG NewAllocationSize = Length;
            BOOLEAN AskForMore = TRUE;

            //
            //  See if this is the Usn Journal to enforce allocation granularity.
            //
            //  ****    Temporary - this support should be generalized with an Scb field
            //                      settable by all callers.
            //

            if (Scb == Vcb->UsnJournal) {

                LONGLONG MaxAllocation;

                //
                //  Limit ourselves to 128 runs.  We don't want to commit in the
                //  middle of the allocation.
                //

                NewAllocationSize = MAXIMUM_RUNS_AT_ONCE * Vcb->BytesPerCluster;

                //
                //  Don't use more than 1/4 of the free space on the volume.
                //

                MaxAllocation = Int64ShllMod32( Vcb->FreeClusters, Vcb->ClusterShift - 2 );

                if (NewAllocationSize > MaxAllocation) {

                    //
                    //  Round down to the Max.  Don't worry if there is nothing, our code
                    //  below will catch this case and the allocation package always rounds
                    //  to a compression unit boundary.
                    //

                    NewAllocationSize = MaxAllocation;
                }

                //
                //  Don't grow by more than the Usn delta.
                //

                if (NewAllocationSize > (LONGLONG) Vcb->UsnJournalInstance.AllocationDelta) {

                    NewAllocationSize = (LONGLONG) Vcb->UsnJournalInstance.AllocationDelta;
                }

                NewAllocationSize += (LONGLONG) Scb->Header.AllocationSize.QuadPart;

                //
                //  Handle possible weird case.
                //

                if (NewAllocationSize < Length) {
                    NewAllocationSize = Length;
                }

                //
                //  Always pad the allocation to a compression unit boundary.
                //

                ASSERT( Scb->CompressionUnit != 0 );
                NewAllocationSize += Scb->CompressionUnit - 1;
                NewAllocationSize &= ~((LONGLONG) (Scb->CompressionUnit - 1));

                AskForMore = FALSE;

            } else if (Scb->Header.PagingIoResource == NULL) {

                //
                //  If the file is sparse then make sure we allocate a full compression unit.
                //  Otherwise we can end up with a partially allocated chunk in the Usn
                //  Journal.
                //

                if (Scb->CompressionUnit != 0) {

                    NewAllocationSize += Scb->CompressionUnit - 1;
                    ((PLARGE_INTEGER) &NewAllocationSize)->LowPart &= ~(Scb->CompressionUnit - 1);
                }

                AskForMore = FALSE;
            }

            //
            //  Add the allocation.  Never ask for extra for logged streams.
            //

            NtfsAddAllocation( IrpContext,
                               FileObject,
                               Scb,
                               LlClustersFromBytes( Scb->Vcb, Scb->Header.AllocationSize.QuadPart ),
                               LlClustersFromBytes(Scb->Vcb, (NewAllocationSize - Scb->Header.AllocationSize.QuadPart)),
                               AskForMore,
                               NULL );


            ExAcquireFastMutex( Scb->Header.FastMutex );

        //
        //  Otherwise see if we have to knock these numbers down...
        //

        } else {

            ExAcquireFastMutex( Scb->Header.FastMutex );
            if ((Length < Scb->Header.ValidDataLength.QuadPart) &&
                (Scb->Header.ValidDataLength.QuadPart != MAXLONGLONG)) {

                Scb->Header.ValidDataLength.QuadPart = Length;
            }

            if (FlagOn( Scb->AttributeFlags, ATTRIBUTE_FLAG_COMPRESSION_MASK ) &&
                (Length < Scb->ValidDataToDisk)) {

                Scb->ValidDataToDisk = Length;
            }
        }

        //
        //  Now put the new size in the Scb.
        //

        Scb->Header.FileSize.QuadPart = Length;
        ExReleaseFastMutex( Scb->Header.FastMutex );

        //
        //  Call our common routine to modify the file sizes.  We are now
        //  done with Length and NewValidDataLength, and we have
        //  PagingIo + main exclusive (so no one can be working on this Scb).
        //  NtfsWriteFileSizes uses the sizes in the Scb, and this is the
        //  one place where in Ntfs where we wish to use a different value
        //  for ValidDataLength.  Therefore, we save the current ValidData
        //  and plug it with our desired value and restore on return.
        //

        NtfsWriteFileSizes( IrpContext,
                            Scb,
                            &Scb->Header.ValidDataLength.QuadPart,
                            FALSE,
                            TRUE,
                            TRUE );

        //
        //  Now update Cc.
        //

        NtfsSetCcFileSizes( FileObject, Scb, (PCC_FILE_SIZES)&Scb->Header.AllocationSize );

    } finally {

        if (CleanupAttrContext) {
            NtfsCleanupAttributeContext( IrpContext, &AttrContext );
        }

    }
}


NTFSAPI
NTSTATUS
NtfsHoldIrpForNewLength (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN PIRP Irp,
    IN LONGLONG Length,
    IN PDRIVER_CANCEL CancelRoutine,
    IN PVOID CapturedData OPTIONAL,
    OUT PVOID *CopyCapturedData OPTIONAL,
    IN ULONG CapturedDataLength
    )

/*++

RoutineDescription:

    This routine may be called to wait until the designated stream exceeds the specified
    length.

Arguments:

    Scb - Supplies the stream to wait on.

    Irp - Supplies the address of the Irp to hold

    Length - Supplies the length to be exceeded.  To wait for any file extend, supply the last seen
             FileSize.  To wait for N new bytes wait for last seen FileSize + N.

    CancelRoutine - Routine to register as the cancel routine.

    CapturedData - Specified if caller wishes to have auxillary data captured to pool.

    CopyCapturedData - Address to store copy of the captured data.

    CapturedDataLength - Length of the auxillary data to capture.  Must be 0 if CapturedData not
                         specified.

Return value:

    NTSTATUS - Status of posting this request.  STATUS_CANCELLED if the irp has been cancelled
        before we could register a callback, STATUS_PENDING if the request was posted without
        problem.  Any other error indicates the irp wasn't posted and our caller needs to
        clean it up.

--*/

{
    PWAIT_FOR_NEW_LENGTH WaitForNewLength;
    NTSTATUS Status = STATUS_PENDING;

    PAGED_CODE();

    //
    //  Allocate and initialize a wait block.
    //

    WaitForNewLength = NtfsAllocatePool( NonPagedPool, QuadAlign(sizeof(WAIT_FOR_NEW_LENGTH)) + CapturedDataLength );
    RtlZeroMemory( WaitForNewLength, sizeof(WAIT_FOR_NEW_LENGTH) );
    if (ARGUMENT_PRESENT(CapturedData)) {
        RtlCopyMemory( Add2Ptr(WaitForNewLength, QuadAlign(sizeof(WAIT_FOR_NEW_LENGTH))),
                       CapturedData,
                       CapturedDataLength );
        CapturedData = Add2Ptr(WaitForNewLength, QuadAlign(sizeof(WAIT_FOR_NEW_LENGTH)));

        *CopyCapturedData = CapturedData;
    }

    WaitForNewLength->Irp = Irp;
    WaitForNewLength->Length = Length;
    WaitForNewLength->Stream = Scb;
    WaitForNewLength->Status = STATUS_SUCCESS;
    WaitForNewLength->Flags = NTFS_WAIT_FLAG_ASYNC;

    //
    //  Prepare the Irp for hanging around.  Only make this call once per Irp.  We occasionally
    //  wake up a waiting Irp and then find we don't have enough data to return.  In that
    //  case we don't want to clean up the 'borrowed' IrpContext and the Irp has already
    //  been prepared.
    //

    if (IrpContext->OriginatingIrp == Irp) {

        NtfsPrePostIrp( IrpContext, Irp );
    }

    //
    //  Synchronize to queue and initialize the wait block.
    //

    ExAcquireFastMutex( Scb->Header.FastMutex );

    if (NtfsSetCancelRoutine( Irp, CancelRoutine, (ULONG_PTR) WaitForNewLength, TRUE )) {

        InsertTailList( &Scb->ScbType.Data.WaitForNewLength, &WaitForNewLength->WaitList );
        IoMarkIrpPending( Irp );

    //
    //  The irp has already been marked for cancel.
    //

    } else {

        Status = STATUS_CANCELLED;
        NtfsFreePool( WaitForNewLength );
    }

    ExReleaseFastMutex( Scb->Header.FastMutex );

    //
    //  Mark the Irp pending and get out.
    //

    return Status;
}


NTFSAPI
NTSTATUS
NtOfsWaitForNewLength (
    IN PSCB Scb,
    IN LONGLONG Length,
    IN ULONG Async,
    IN PIRP Irp,
    IN PDRIVER_CANCEL CancelRoutine,
    IN PLARGE_INTEGER Timeout OPTIONAL
    )

/*++

RoutineDescription:

    This routine may be called to wait until the designated stream exceeds the specified
    length.

Arguments:

    Scb - Supplies the stream to wait on.

    Length - Supplies the length to be exceeded.  To wait for any file extend, supply the last seen
             FileSize.  To wait for N new bytes wait for last seen FileSize + N.

    Async - Indicates if we want to complete this request in another thread in
        the case of cancel.

    Irp - Supplies Irp of current request, so that wait can be skipped if Irp has been cancelled.

    CancelRoutine - This is the cancel routine to store in the Irp.

    TimeOut - Supplies an standard optional timeout spec, in case the caller wants to set
              a max time to wait.

Return value:

    NTSTATUS - Status to proceed with the request.  It may be STATUS_SUCCESS, STATUS_TIMEOUT or
        STATUS_CANCELLED.  It may also be some other error specific to this type of request.
        In general the caller may wish to ignore the status code since they own the Irp now
        and are responsible for completing it.

--*/

{
    PWAIT_FOR_NEW_LENGTH WaitForNewLength;
    LONGLONG OriginalLength = Scb->Header.FileSize.QuadPart;
    NTSTATUS Status = STATUS_SUCCESS;

    PAGED_CODE();

    //
    //  Allocate and initialize a wait block.
    //

    WaitForNewLength = NtfsAllocatePool( NonPagedPool, sizeof( WAIT_FOR_NEW_LENGTH ));
    WaitForNewLength->Irp = Irp;
    WaitForNewLength->Length = Length;
    WaitForNewLength->Stream = Scb;
    WaitForNewLength->Status = STATUS_SUCCESS;

    //
    //  Take different action if this is async or sync.
    //

    if (Async) {

        WaitForNewLength->Flags = NTFS_WAIT_FLAG_ASYNC;

    } else {

        WaitForNewLength->Flags = 0;
        KeInitializeEvent( &WaitForNewLength->Event, NotificationEvent, FALSE );
    }

    //
    //  Test if we need to wait at all.
    //

    ExAcquireFastMutex( Scb->Header.FastMutex );

    //
    //  Has the length already changed?  If not we must wait.
    //

    if (Scb->Header.FileSize.QuadPart <= Length) {

        //
        //  Now set up the cancel routine.  Return cancel if the user has
        //  already cancelled this.  Otherwise set up to wait.
        //

        if (NtfsSetCancelRoutine( Irp, CancelRoutine, (ULONG_PTR) WaitForNewLength, Async )) {

            InsertTailList( &Scb->ScbType.Data.WaitForNewLength, &WaitForNewLength->WaitList );
            ExReleaseFastMutex( Scb->Header.FastMutex );

            //
            //  Now wait for someone to signal the length change.
            //

            if (!Async) {

                do {
                    Status = KeWaitForSingleObject( &WaitForNewLength->Event,
                                                    Executive,
                                                    (KPROCESSOR_MODE)(ARGUMENT_PRESENT(Irp) ?
                                                                        Irp->RequestorMode :
                                                                        KernelMode),
                                                    TRUE,
                                                    Timeout );

                    //
                    //  If the system timed out but there was no change in the file length then
                    //  we want to wait for the first change of the file.  Wait again but without
                    //  a timeout and a length of the current size + 1.  This satisfies the timeout
                    //  semantics which are don't wait for the full user length request to be satisfied
                    //  if it doesn't occur within the timeout period.  Return either what has changed
                    //  in that time or the first change which occurs if nothing changed within the
                    //  timeout period.
                    //

                    if ((Status == STATUS_TIMEOUT) &&
                        ARGUMENT_PRESENT( Timeout ) &&
                        (Scb->Header.FileSize.QuadPart == OriginalLength)) {

                        Timeout = NULL;
                        WaitForNewLength->Length = OriginalLength + 1;

                        //
                        //  Set the status to STATUS_KERNEL_APC so we will retry.
                        //

                        Status = STATUS_KERNEL_APC;
                        continue;
                    }

                } while (Status == STATUS_KERNEL_APC);

                //
                //  Make sure to clear the cancel routine.  We don't care if
                //  a cancel is underway here.
                //

                ExAcquireFastMutex( Scb->Header.FastMutex );

                //
                //  Make a timeout look like STATUS_SUCCESS.  Otherwise return the error.
                //

                if (Status == STATUS_TIMEOUT) {

                    Status = STATUS_SUCCESS;

                    //
                    //  Clear the cancel routine.
                    //

                    NtfsClearCancelRoutine( WaitForNewLength->Irp );

                } else {

                    //
                    //  If the wait completed with success then check for the error
                    //  in the wait block.
                    //

                    if (Status == STATUS_SUCCESS) {

                        Status = WaitForNewLength->Status;

                    //
                    //  Clear the cancel routine.
                    //

                    } else {

                        NtfsClearCancelRoutine( WaitForNewLength->Irp );
                    }
                }

                RemoveEntryList( &WaitForNewLength->WaitList );
                ExReleaseFastMutex( Scb->Header.FastMutex );
                NtfsFreePool( WaitForNewLength );

            //
            //  The current thread is finished with the Irp.
            //

            } else {

                Status = STATUS_PENDING;
            }

        //
        //  The irp has already been marked for cancel.
        //

        } else {

            ExReleaseFastMutex( Scb->Header.FastMutex );
            NtfsFreePool( WaitForNewLength );
            Status = STATUS_CANCELLED;
        }

    } else {

        ExReleaseFastMutex( Scb->Header.FastMutex );
        NtfsFreePool( WaitForNewLength );
    }


    return Status;
}


VOID
NtOfsPostNewLength (
    IN PIRP_CONTEXT IrpContext OPTIONAL,
    IN PSCB Scb,
    IN BOOLEAN WakeAll
    )

/*++

RoutineDescription:

    This routine may be called to wake one or more waiters based on the desired FileSize change,
    or to unconditionally wake all waiters (such as for a shutdown condition).

    NOTE:  The caller must have the FsRtl header mutex acquired when calling this routine.

Arguments:

    Scb - Supplies the stream to act on.

    WakeAll - Supplies TRUE if all waiters should be unconditionally woken.

Return value:

    None.

--*/

{
    PWAIT_FOR_NEW_LENGTH WaitForNewLength, WaiterToWake;

    ASSERT(FIELD_OFFSET(WAIT_FOR_NEW_LENGTH, WaitList) == 0);

    PAGED_CODE();

    ExAcquireFastMutex( Scb->Header.FastMutex );
    WaitForNewLength = (PWAIT_FOR_NEW_LENGTH)Scb->ScbType.Data.WaitForNewLength.Flink;

    while (WaitForNewLength != (PWAIT_FOR_NEW_LENGTH)&Scb->ScbType.Data.WaitForNewLength) {

        //
        //  If we are supposed to wake this guy, then move our pointer to the next guy
        //  first, then wake him, setting his event after removing him from the list,
        //  since setting the event will cause him to eventually reuse the stack space
        //  containing the wait block.
        //

        if ((Scb->Header.FileSize.QuadPart > WaitForNewLength->Length) || WakeAll) {
            WaiterToWake = WaitForNewLength;
            WaitForNewLength = (PWAIT_FOR_NEW_LENGTH)WaitForNewLength->WaitList.Flink;

            //
            //  If this is for an asynchronous Irp, then remove him from the list and
            //  drop the mutex to do further processing.  We only do further processing
            //  if there is not currently a cancel thread active for this Irp.
            //
            //  NOTE:   This code currently relies on the fact that there is just one
            //          caller to the routine to hold an Irp.  If more such caller's
            //          surface, then the routine address would have to be stored in
            //          the wait context.
            //
            //  If cancel is active then we will skip over this Irp.
            //

            if (NtfsClearCancelRoutine( WaiterToWake->Irp )) {

                if (FlagOn( WaiterToWake->Flags, NTFS_WAIT_FLAG_ASYNC )) {

                    //
                    //  Make sure we decrement the reference count in the Scb.
                    //

                    InterlockedDecrement( &Scb->CloseCount );
                    RemoveEntryList( &WaiterToWake->WaitList );
                    ExReleaseFastMutex( Scb->Header.FastMutex );

                    //
                    //  Nothing really should go wrong, unless we get an I/O error,
                    //  none the less, we want to stop any exceptions and complete
                    //  the request ourselves rather than impact our caller.
                    //

                    if (ARGUMENT_PRESENT( IrpContext )) {

                        try {
                            NtfsReadUsnJournal( IrpContext,
                                                WaiterToWake->Irp,
                                                FALSE );
                        } except(NtfsExceptionFilter( NULL, GetExceptionInformation())) {
                            NtfsCompleteRequest( NULL, WaiterToWake->Irp, GetExceptionCode() );
                        }

                    //
                    //  Assume the only caller with no IrpContext is cancelling the request.
                    //

                    } else {

                        NtfsCompleteRequest( NULL, WaiterToWake->Irp, STATUS_CANCELLED );
                    }

                    //
                    //  Free the wait block and go back to the beginning of the list.
                    //  Is it possible that we can into a continuous loop here?  We may
                    //  need a strategy to recognize which entries we have visited
                    //  in this loop.
                    //

                    NtfsFreePool( WaiterToWake );
                    ExAcquireFastMutex( Scb->Header.FastMutex );
                    WaitForNewLength = (PWAIT_FOR_NEW_LENGTH)Scb->ScbType.Data.WaitForNewLength.Flink;

                } else {

                    KeSetEvent( &WaiterToWake->Event, 0, FALSE );
                }
            }

        } else {

            WaitForNewLength = (PWAIT_FOR_NEW_LENGTH)WaitForNewLength->WaitList.Flink;
        }
    }
    ExReleaseFastMutex( Scb->Header.FastMutex );
}

NTFSAPI
VOID
NtOfsFlushAttribute (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN ULONG Purge
    )

/*++

Routine Description:

    This routine flushes the specified attribute, and optionally purges it from the cache.

Arguments:

    Scb - Supplies an Scb as the previously returned handle for this attribute.

    Purge - Supplies TRUE if the attribute is to be purged.

Return Value:

    None (Deleting a nonexistant index is benign).

--*/

{
    PAGED_CODE();

    if (Purge) {
        NtfsFlushAndPurgeScb( IrpContext, Scb, NULL );
    } else {
        NtfsFlushUserStream( IrpContext, Scb, NULL, 0 );
    }
}


NTFSAPI
VOID
NtOfsPutData (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN LONGLONG Offset,
    IN ULONG Length,
    IN PVOID Data OPTIONAL
    )

/*++

Routine Description:

    This routine is called to update a range of a recoverable stream.

Arguments:

    Scb - Scb for the stream to zero.

    Offset - Offset in stream to update.

    Length - Length of stream to update in bytes.

    Data - Data to update stream with if specified, else range should be zeroed.

Return Value:

    None.

--*/

{
    BOOLEAN WriteToEof = FALSE;

    PAGED_CODE();

    ASSERT(FlagOn(Scb->ScbState, SCB_STATE_MODIFIED_NO_WRITE));

    //
    //  Handle Put to end of file.
    //

    if (Offset < 0) {
        WriteToEof = TRUE;
        Offset = Scb->Header.FileSize.QuadPart;
        NtOfsSetLength( IrpContext, Scb, Offset + Length );
    }

    ASSERT((Offset + Length) <= Scb->Header.FileSize.QuadPart);

    //
    //  First handle the resident case.
    //

    if (FlagOn(Scb->ScbState, SCB_STATE_ATTRIBUTE_RESIDENT)) {

        ATTRIBUTE_ENUMERATION_CONTEXT Context;
        PFILE_RECORD_SEGMENT_HEADER FileRecord;
        PATTRIBUTE_RECORD_HEADER Attribute;
        ULONG RecordOffset, AttributeOffset;
        PVCB Vcb = Scb->Vcb;

        NtfsInitializeAttributeContext( &Context );

        try {

            //
            //  Lookup and pin the attribute.
            //

            NtfsLookupAttributeForScb( IrpContext, Scb, NULL, &Context );
            NtfsPinMappedAttribute( IrpContext, Vcb, &Context );

            //
            //  Extract the relevant pointers and calculate offsets.
            //

            FileRecord = NtfsContainingFileRecord(&Context);
            Attribute = NtfsFoundAttribute(&Context);
            RecordOffset = PtrOffset(FileRecord, Attribute);
            AttributeOffset = Attribute->Form.Resident.ValueOffset + (ULONG)Offset;

            //
            //  Log the change while we still have the old data.
            //

            FileRecord->Lsn =
            NtfsWriteLog( IrpContext,
                          Vcb->MftScb,
                          NtfsFoundBcb(&Context),
                          UpdateResidentValue,
                          Data,
                          Length,
                          UpdateResidentValue,
                          Add2Ptr(Attribute, Attribute->Form.Resident.ValueOffset + (ULONG)Offset),
                          Length,
                          NtfsMftOffset(&Context),
                          RecordOffset,
                          AttributeOffset,
                          Vcb->BytesPerFileRecordSegment );

            //
            //  Now update this data by calling the same routine as restart.
            //

            NtfsRestartChangeValue( IrpContext,
                                    FileRecord,
                                    RecordOffset,
                                    AttributeOffset,
                                    Data,
                                    Length,
                                    FALSE );

            //
            //  If there is a stream for this attribute, then we must update it in the
            //  cache, copying from the attribute itself in order to handle the zeroing
            //  (Data == NULL) case.
            //

            if (Scb->FileObject != NULL) {
                CcCopyWrite( Scb->FileObject,
                             (PLARGE_INTEGER)&Offset,
                             Length,
                             TRUE,
                             Add2Ptr(Attribute, AttributeOffset) );
            }

            //
            //  Optionally update ValidDataLength
            //

            Offset += Length;
            if (Offset > Scb->Header.ValidDataLength.QuadPart) {
                Scb->Header.ValidDataLength.QuadPart = Offset;
            }

        } finally {
            NtfsCleanupAttributeContext( IrpContext, &Context );
        }

    //
    //  Now handle the nonresident case.
    //

    } else {

        PVOID Buffer;
        LONGLONG NewValidDataLength = Offset + Length;
        PBCB Bcb = NULL;
        ULONG PageOffset = (ULONG)Offset & (PAGE_SIZE - 1);
        ULONG MovingBackwards = FALSE;

        ASSERT(Scb->FileObject != NULL);

        //
        //  If we are starting beyond ValidDataLength, then recurse to
        //  zero what we need.
        //

        if (Offset > Scb->Header.FileSize.QuadPart) {

            ASSERT((Offset - Scb->Header.FileSize.QuadPart) <= MAXULONG);

            NtOfsPutData( IrpContext,
                          Scb,
                          Scb->Header.FileSize.QuadPart,
                          (ULONG)(Offset - Scb->Header.FileSize.QuadPart),
                          NULL );
        }

        try {

            //
            //  Now loop until there are no more pages with new data
            //  to log.
            //

            while (Length != 0) {

                ULONG BytesThisPage;

                NtfsPinStream( IrpContext,
                               Scb,
                               Offset,
                               1,
                               &Bcb,
                               &Buffer );

                //
                //  Compute the number of bytes of for this page, assuming a
                //  forward move.
                //

                BytesThisPage = PAGE_SIZE - PageOffset;

                if (BytesThisPage > Length) {
                    BytesThisPage = Length;
                }

                //
                //  See if we need to switch to moving backwards.
                //

                if (!MovingBackwards &&
                    ((PCHAR)Buffer > (PCHAR)Data) &&
                    (Data != NULL) &&
                    ((PageOffset + Length) > PAGE_SIZE)) {

                    //
                    //  We are now doing the move backwards - we will only do this once.
                    //

                    MovingBackwards = TRUE;

                    //
                    //  Figure out how many bytes there are to move in the last page, and
                    //  then see how much we have to adjust our Offset and pointers by to
                    //  get to the last page (temporarily in PageOffset).
                    //

                    BytesThisPage = ((PageOffset + Length - 1) & (PAGE_SIZE - 1)) + 1;
                    PageOffset = Length - BytesThisPage;

                    //
                    //  Now adjust everyone by the right amount.
                    //

                    Offset += PageOffset;
                    Data = Add2Ptr( Data, PageOffset );
                    Buffer = Add2Ptr( Buffer, PageOffset );

                    //
                    //  Of course the page offset in the last page is 0.
                    //

                    PageOffset = 0;
                }

                //
                //  Now log the changes to this page.
                //

                (VOID)
                NtfsWriteLog( IrpContext,
                              Scb,
                              Bcb,
                              UpdateNonresidentValue,
                              Data,
                              BytesThisPage,
                              WriteToEof ? Noop : UpdateNonresidentValue,
                              WriteToEof ? NULL : Buffer,
                              WriteToEof ? 0 : BytesThisPage,
                              Offset - PageOffset,
                              PageOffset,
                              0,
                              PageOffset + BytesThisPage );

                //
                //  Move the data into place.
                //

                if (Data != NULL) {
                    RtlMoveMemory( Buffer, Data, BytesThisPage );
                } else {
                    RtlZeroMemory( Buffer, BytesThisPage );
                }

                //
                //  Now we pin the page and calculate the beginning
                //  buffer in the page.
                //

                NtfsUnpinBcb( IrpContext, &Bcb );

                Length -= BytesThisPage;
                PageOffset = 0;

                if (MovingBackwards) {

                    //
                    //  Now decrement the counts and move through the
                    //  caller's buffer.
                    //

                    BytesThisPage = PAGE_SIZE;
                    if (Length < PAGE_SIZE) {
                        PageOffset = PAGE_SIZE - Length;
                        BytesThisPage = Length;
                    }
                    Data = Add2Ptr( Data, (0 - BytesThisPage) );
                    Offset -= BytesThisPage;

                } else {

                    //
                    //  Now decrement the counts and move through the
                    //  caller's buffer.
                    //

                    if (Data != NULL) {
                        Data = Add2Ptr( Data, BytesThisPage );
                    }
                    Offset += BytesThisPage;
                }
            }

            //
            //  Optionally update ValidDataLength
            //

            if (NewValidDataLength > Scb->Header.ValidDataLength.QuadPart) {

                Scb->Header.ValidDataLength.QuadPart = NewValidDataLength;
                NtfsWriteFileSizes( IrpContext, Scb, &NewValidDataLength, TRUE, TRUE, TRUE );

                //
                //  See if we have to wake anyone.
                //

                if (!IsListEmpty(&Scb->ScbType.Data.WaitForNewLength)) {
                    NtfsPostToNewLengthQueue( IrpContext, Scb );
                }
            }

        } finally {
            NtfsUnpinBcb( IrpContext, &Bcb );
        }
    }
}


//
//  The following prototypes are here only for someone external to Ntfs (such as EFS)
//  trying to link to Ntfs using ntfsexp.h.
//

NTFSAPI
VOID
NtOfsMapAttribute (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN LONGLONG Offset,
    IN ULONG Length,
    OUT PVOID *Buffer,
    OUT PMAP_HANDLE MapHandle
    )

/*++

Routine Description:

    NtOfsMapAttribute maps the given region of an Scb. Its a thin wrapper
    around CcMapData.

Arguments:

    IrpContext - Supplies the irpcontext associated with the current operation

    Scb - Scb to map data from

    Offset - offset into data

    Length - length of region to be pinned

    Buffer - returned buffer with pinned data virtual address

    MapHandle - returned map handle used to manage the pinned region.

Return Value:

    None

--*/

{
    PAGED_CODE( );
    UNREFERENCED_PARAMETER( IrpContext );
    CcMapData( Scb->FileObject, (PLARGE_INTEGER)&Offset, Length, TRUE, &MapHandle->Bcb, Buffer );
#ifdef MAPCOUNT_DBG
    IrpContext->MapCount++;
#endif

    MapHandle->FileOffset = Offset;
    MapHandle->Length = Length;
    MapHandle->Buffer = *(PVOID *)Buffer;
}


NTFSAPI
VOID
NtOfsPreparePinWrite (
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN LONGLONG Offset,
    IN ULONG Length,
    OUT PVOID *Buffer,
    OUT PMAP_HANDLE MapHandle
    )

/*++

Routine Description:

    NtOfsPreparePinWrite maps and pins a portion of the specified attribute and
    returns a pointer to the memory.  This is equivalent to doing a NtOfsMapAttribute
    followed by NtOfsPinRead and NtOfsDirty but is more efficient.

Arguments:

    IrpContext - Supplies the irpcontext associated with the current operation

    Scb - Scb to pin in preparation for a write

    Offset - offset into data

    Length - length of region to be pinned

    Buffer - returned buffer with pinned data virtual address

    MapHandle - returned map handle used to manage the pinned region.

Return Value:

    None

--*/

{
    UNREFERENCED_PARAMETER( IrpContext );
    if ((Offset + Length) > Scb->Header.AllocationSize.QuadPart) {
        ExRaiseStatus(STATUS_END_OF_FILE);
    }
    CcPreparePinWrite( Scb->FileObject, (PLARGE_INTEGER)&Offset, Length, FALSE, TRUE, &MapHandle->Bcb, Buffer );
#ifdef MAPCOUNT_DBG
    IrpContext->MapCount++;
#endif

    MapHandle->FileOffset = Offset;
    MapHandle->Length = Length;
    MapHandle->Buffer = Buffer;
}


NTFSAPI
VOID
NtOfsPinRead(
    IN PIRP_CONTEXT IrpContext,
    IN PSCB Scb,
    IN LONGLONG Offset,
    IN ULONG Length,
    OUT PMAP_HANDLE MapHandle
    )

/*++

Routine Description:

    NtOfsPinRead pins a section of a map and read in all pages from the mapped
    attribute.  Offset and Length must describe a byte range which is equal to
    or included by the original mapped range.

Arguments:

    IrpContext - Supplies the irpcontext associated with the current operation

    Scb - Scb to pin data for reads in

    Offset - offset into data

    Length - length of region to be pinned

    MapHandle - returned map handle used to manage the pinned region.

Return Value:

    None

--*/

{
    UNREFERENCED_PARAMETER( IrpContext );
    ASSERT( MapHandle->Bcb != NULL );
    ASSERT( (Offset >= MapHandle->FileOffset) && ((Offset + Length) <= (MapHandle->FileOffset + MapHandle->Length)) );
    CcPinMappedData( Scb->FileObject, (PLARGE_INTEGER)&Offset, Length, TRUE, &MapHandle->Bcb );
    MapHandle->FileOffset = Offset;
    MapHandle->Length = Length;
}


NTFSAPI
VOID
NtOfsReleaseMap (
    IN PIRP_CONTEXT IrpContext,
    IN PMAP_HANDLE MapHandle
    )

/*++

Routine Description:

    This routine unmaps/unpins a mapped portion of an attribute.

Arguments:

    IrpContext - Supplies the irpcontext associated with the current operation

    MapHandle - Supplies map handle containing the bcb to be released.

Return Value:

    None

--*/

{
    UNREFERENCED_PARAMETER( IrpContext );

    if (MapHandle->Bcb != NULL) {
        CcUnpinData( MapHandle->Bcb );
#ifdef MAPCOUNT_DBG
        IrpContext->MapCount--;
#endif
        MapHandle->Bcb = NULL;
    }
}

