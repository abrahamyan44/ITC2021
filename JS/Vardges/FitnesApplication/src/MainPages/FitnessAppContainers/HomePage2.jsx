import React, { useState } from 'react'

import Icon from '@mdi/react'
import {
    mdiRun,
    mdiYoga,
    mdiPlus,
    mdiHome,
    mdiBell,
    mdiTicket,
    mdiAccount,
    mdiArmFlex,
    mdiDumbbell,
    mdiChartLine,
    mdiChevronRight,
    mdiFood,
} from '@mdi/js'

import {
    H4,
    H5,
    H6,
    Card,
    Body2,
    Caption,
    Subtitle2,
    IconButton,
    withResize,
    ToggleButton,
    ProgressCircular,
} from 'ui-neumorphism'


function HomePage2({ dark, size }) {
    return (
        <Card flat dark={dark} className='fitness-app-container'>
            <Card flat className='fitness-app-wrapper overflow-hidden'>
                <Card
                    rounded
                    width={300}
                    height={600}
                    className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
                        } overflow-hidden`}
                >
                    <div
                        style={{
                            display: 'flex',
                            marginTop: '8px',
                            alignItems: 'center',
                            justifyContent: 'space-between'
                        }}
                    >
                        <H4 dark={dark} style={{ fontWeight: '500' }}>
                            Plan list
                     </H4>
                        <IconButton
                            size='small'
                            rounded
                            text={false}
                            color='var(--primary)'
                            dark={dark}
                        >
                            <Icon path={mdiPlus} size={0.8} />
                        </IconButton>
                    </div>
                    <div
                        style={{
                            display: 'flex',
                            width: '252px',
                            alignItems: 'center',
                            justifyContent: 'center'
                        }}
                    >
                        <Card
                            dark={dark}
                            elevation={3}
                            style={{
                                display: 'flex',
                                marginTop: '32px',
                                width: '194px',
                                height: '194px',
                                borderRadius: '150px',
                                alignItems: 'center',
                                justifyContent: 'center'
                            }}
                        >
                            <Card flat>
                                <Icon path={mdiRun} size={2.5} color='var(--primary)' />
                                <H5 style={{ padding: '4px 0px' }}>8,690</H5>

                                <Caption style={{ padding: '4px 0px' }} secondary>
                                    Goal: 12k
                             </Caption>
                            </Card>
                        </Card>
                    </div>
                    <Card
                        rounded={false}
                        elevation={3}
                        style={{
                            display: 'flex',
                            padding: '16px',
                            marginTop: '36px',
                            alignItems: 'center',
                            justifyContent: 'space-between'
                        }}
                    >
                        <Card
                            flat
                            style={{
                                display: 'flex',
                                alignItems: 'center'
                            }}
                        >
                            <Icon path={mdiArmFlex} size={1} color='var(--primary)' />
                            <Card flat style={{ marginLeft: '12px' }}>
                                <Subtitle2 style={{ margin: '0px 0px' }}>
                                    Completed: 3 group
                            </Subtitle2>
                                <Caption secondary component='span'>
                                    Goal: 4 group
                        </Caption>
                            </Card>
                        </Card>
                        <ProgressCircular value={75} color='var(--primary)'>
                            75%
                    </ProgressCircular>
                    </Card>
                    <Card
                        rounded={false}
                        elevation={2}
                        style={{
                            display: 'flex',
                            padding: '16px',
                            marginTop: '20px',
                            alignItems: 'center',
                            justifyContent: 'space-between'
                        }}
                    >
                        <Card
                            flat
                            style={{
                                display: 'flex',
                                alignItems: 'center'
                            }}
                        >
                            <Icon path={mdiDumbbell} size={1} color='var(--primary)' />
                            <Card flat style={{ marginLeft: '12px' }}>
                                <Subtitle2 style={{ margin: '0px 0px' }}>
                                    Completed: 6 group
                            </Subtitle2>
                                <Caption secondary component='span'>
                                    Goal: 6 group
                            </Caption>
                            </Card>
                        </Card>
                        <ProgressCircular value={100} color='var(--primary)'>
                            100%
                </ProgressCircular>
                    </Card>
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={0.9} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} color='var(--primary)'>
                            <Icon path={mdiChartLine} size={0.8} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} color='var(--primary)'>
                            <Icon path={mdiFood} size={0.8} />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={0.8} />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={0.9} />
                        </ToggleButton>
                    </div>
                </Card>
            </Card>
        </Card>
    )
}

export default HomePage2;