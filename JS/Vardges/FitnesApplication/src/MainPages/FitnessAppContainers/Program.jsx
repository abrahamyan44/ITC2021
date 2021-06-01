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


function Program({dark,size}) {
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
            <H4 style={{ fontWeight: '500', marginTop: '8px' }}>Program</H4>
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                justifyContent: 'space-between'
              }}
            >
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '16px 0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiArmFlex} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Arm</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>In progress..</Caption>
              </Card>
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '16px 0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiDumbbell} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Weight</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>Have finished</Caption>
              </Card>
            </div>
            <div
              style={{
                display: 'flex',
                marginTop: '4px',
                justifyContent: 'space-between'
              }}
            >
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiRun} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Run</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>In progress..</Caption>
              </Card>
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiYoga} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Yoga</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>No task</Caption>
              </Card>
            </div>
            <H6 style={{ margin: '24px 0px 16px 0px' }}>Courses Collection</H6>
            <Card rounded={false} elevation={2} style={{ padding: '16px' }}>
              <div
                style={{
                  display: 'flex'
                }}
              >
                <Card
                  outlined
                  dark={dark}
                  style={{ padding: '4px', width: '46px', height: '46px' }}
                >
                  <Icon path={mdiTicket} size={1.5} color='var(--primary)' />
                </Card>
                <Card
                  flat
                  dark={dark}
                  style={{ marginLeft: '12px', overflow: 'unset' }}
                >
                  <Subtitle2 style={{ margin: '0px 0px' }}>
                    Courses I attended
                  </Subtitle2>
                  <Card
                    flat
                    style={{
                      display: 'flex',
                      overflow: 'unset',
                      alignItems: 'center'
                    }}
                  >
                    <Caption secondary component='span'>
                      11 courses in total
                    </Caption>
                    <IconButton
                      style={{ marginLeft: '24px' }}
                      text={false}
                      dark={dark}
                      size='small'
                      rounded
                    >
                      <Icon
                        path={mdiChevronRight}
                        size={0.7}
                        color='var(--primary)'
                      />
                    </IconButton>
                  </Card>
                </Card>
              </div>
            </Card>
            <div className='fitness-app-nav-bar'>
              <ToggleButton selected dark={dark}>
                <Icon path={mdiHome} size={0.9} color='var(--primary)' />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon
                  path={mdiChartLine}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>

              <ToggleButton dark={dark}>
                <Icon
                  path={mdiFood}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon
                  path={mdiBell}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon
                  path={mdiAccount}
                  size={0.9}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>
            </div>
          </Card>
        </Card>
      </Card>
    )
}

export default Program;
